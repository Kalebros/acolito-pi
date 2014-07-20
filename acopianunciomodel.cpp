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

#include "acopianunciomodel.h"

AcoPiAnuncioModel::AcoPiAnuncioModel(QObject *parent, QString path) :
    QAbstractListModel(parent)
{
    _path=path;

    _filtros << "*.bmp" << "*.jpg" << "*.png";

    if(!_path.isEmpty())
    {
        QDir dir(_path);
        dir.setNameFilters(_filtros);
        dir.setFilter(QDir::Files);

        QFileInfoList archivos=dir.entryInfoList();
        foreach(QFileInfo info,archivos)
            _listaAnuncios << info.absoluteFilePath();
    }
}

QString AcoPiAnuncioModel::getPath() const
{
    return _path;
}

void AcoPiAnuncioModel::setPath(const QString path)
{
    beginResetModel();
    _path=path;
    _listaAnuncios.clear();

    QDir dir(_path);
    dir.setNameFilters(_filtros);
    dir.setFilter(QDir::Files);

    QFileInfoList archivos=dir.entryInfoList();
    foreach(QFileInfo info,archivos)
        _listaAnuncios << info.absoluteFilePath();
    endResetModel();
}

void AcoPiAnuncioModel::reloadModel()
{
    beginResetModel();
    _listaAnuncios.clear();

    QDir directorio(_path);
    directorio.setNameFilters(_filtros);
    directorio.setFilter(QDir::Files);

    QFileInfoList archivos=directorio.entryInfoList();
    foreach(QFileInfo info,archivos)
        _listaAnuncios << info.absoluteFilePath();
    endResetModel();
}

int AcoPiAnuncioModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return _listaAnuncios.count();
}

QVariant AcoPiAnuncioModel::data(const QModelIndex &index, int role) const
{
    QVariant res;
    if(!index.isValid())
        return QVariant();

    if(role==Qt::DisplayRole)
    {
        res=_listaAnuncios.at(index.row());
    }

    return res;
}
