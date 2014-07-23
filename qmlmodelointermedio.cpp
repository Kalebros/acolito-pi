/***************************************************************************/
//    Acolito-pi, visualizador de actividades de MyAcolito para Raspberry Pi
//    Copyright (C) 2014, Antonio Ramírez Marti (morgulero@gmail.com)

//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.

//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.

//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
/***************************************************************************/

#include "qmlmodelointermedio.h"

QmlModeloIntermedio::QmlModeloIntermedio(QAbstractItemModel *mBase, QObject *parent) :
    QSortFilterProxyModel(parent),
    _modeloBase(mBase)
{
    if(_modeloBase) {
        QSortFilterProxyModel::setSourceModel(_modeloBase);
        generateRoles();
    }
    _horaFija=QTime();
    _fechaFija=QDate();

    _isHoraFija=false;
    _isFechaFija=false;
}


void QmlModeloIntermedio::generateRoles()
{
    if(!_roleNames.isEmpty())
        _roleNames.clear();

    int numCol=QSortFilterProxyModel::columnCount();

    for(int i=0;i<numCol;i++) {
        _roleNames[Qt::UserRole + i + 1]=this->sourceModel()->headerData(i,Qt::Horizontal,Qt::DisplayRole).toByteArray();
    }

}

QVariant QmlModeloIntermedio::data(const QModelIndex &index, int role) const
{
    if(index.row()>=rowCount()) {
        return QString("");
    }

    if(role<Qt::UserRole) {
        return QSortFilterProxyModel::data(index,role);
    }

    else {
        return QSortFilterProxyModel::data(this->index(index.row(),role - Qt::UserRole -1),Qt::DisplayRole);
    }

    return QVariant();
}

void QmlModeloIntermedio::setModeloBase(QAbstractItemModel *mBase)
{
    _modeloBase=mBase;
    QSortFilterProxyModel::setSourceModel(mBase);
    generateRoles();
}

bool QmlModeloIntermedio::reloadModelo()
{
    return false;
}

bool QmlModeloIntermedio::isFechaFija() const
{
    return _isFechaFija;
}

bool QmlModeloIntermedio::isHoraFija() const
{
    return _isHoraFija;
}

QDate QmlModeloIntermedio::getFechaFija() const
{
    return _fechaFija;
}

QTime QmlModeloIntermedio::getHoraFija() const
{
    return _horaFija;
}

void QmlModeloIntermedio::setFechaFija(QDate fecha)
{
    _fechaFija=fecha;
    _isFechaFija=true;
    reloadModelo();
}

void QmlModeloIntermedio::setHoraFija(QTime hora)
{
    _horaFija=hora;
    _isHoraFija=true;
    reloadModelo();
}

void QmlModeloIntermedio::unsetFechaFija()
{
    _isFechaFija=false;
}

void QmlModeloIntermedio::unsetHoraFija()
{
    _isHoraFija=false;
}
