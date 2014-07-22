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

#include "qmlmiquerymodel.h"

QmlMIQueryModel::QmlMIQueryModel(QAbstractItemModel *mBase, QObject *parent) :
    QmlModeloIntermedio(mBase,parent)
{
}

bool QmlMIQueryModel::reloadModelo()
{
    beginResetModel();
    QSqlQueryModel *mQuery=qobject_cast<QSqlQueryModel*>(sourceModel());

    mQuery->setQuery(mQuery->query().lastQuery(),QSqlDatabase::database());
    setSourceModel(mQuery);
    endResetModel();

    if(mQuery->rowCount())
        return true;
    else return false;
}
