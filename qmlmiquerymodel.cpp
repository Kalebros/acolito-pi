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

QmlMIQueryModel::QmlMIQueryModel(QObject *parent, QDate f, QTime h) :
    QmlModeloIntermedio(0,f,h,parent)
{
    _internBasicQuery="SELECT nombre,tActividad as tipo, DATE_FORMAT(dia,'%W') as dia, "
            "DATE_FORMAT(horaInicio, '%k:%i') as hInicio, DATE_FORMAT(horaFin, '%k:%i') as hFin, "
            "minimoParticipantes as minParticipantes,maximoParticipantes as maxParticipantes,lugar,"
            "descripcion,requisitos FROM actividad WHERE dia='%1' AND "
            "horaInicio BETWEEN '%2' AND '%3' ORDER BY horaInicio ASC";

    QSqlQueryModel *mQuery=new QSqlQueryModel(this);

    //Generar query
    QDate fecha;
    QTime cTime;

    if(!_isFechaFija)
        fecha=QDate::currentDate();
    else fecha=_fechaFija;

    if(!_isHoraFija)
        cTime=QTime::currentTime();
    else cTime=_horaFija;

    //Establecer hora para el siguiente cambio
    _nextChange=QTime(cTime.hour(),0).addSecs(60*60);

    _hPosterior=QTime(cTime.hour(),0).addSecs(60*60);
    _hAnterior=QTime(cTime.hour(),0).addSecs(-(60*60));


    QString query=_internBasicQuery.arg(fecha.toString("yyyy-MM-dd")).arg(_hAnterior.toString("hh:mm:00")).arg(_hPosterior.toString("hh:mm:00"));
    mQuery->setQuery(query,QSqlDatabase::database());
    _modeloBase=mQuery;

    QSortFilterProxyModel::setSourceModel(_modeloBase);
    generateRoles();
}

bool QmlMIQueryModel::reloadModelo()
{
    beginResetModel();
    QSqlQueryModel *mQuery=qobject_cast<QSqlQueryModel*>(_modeloBase);
    //Generar query
    QDate fecha;
    QTime cTime;

    if(!_isFechaFija)
        fecha=QDate::currentDate();
    else fecha=_fechaFija;

    if(!_isHoraFija) {
        cTime=QTime::currentTime();
        cTime=cTime.addSecs(_clockDrift);
    }
    else cTime=_horaFija;

    //Comprobamos si es necesario hacer el cambio de hora
    //Para depurar, obligamos a realizar el cambio siempre

//    _nextChange=_nextChange.addSecs(60*60);
//    _hPosterior=QTime(_nextChange).addSecs(60*60);
//    _hAnterior=QTime(_nextChange).addSecs(-(60*60));

    if(cTime.msecsTo(_nextChange)<=0) {
        _nextChange=_nextChange.addSecs(60*60);
        _hPosterior=QTime(cTime.hour(),0).addSecs(60*60);
        _hAnterior=QTime(cTime.hour(),0).addSecs(-(60*60));
    }

    QString query=_internBasicQuery.arg(fecha.toString("yyyy-MM-dd")).arg(_hAnterior.toString("hh:mm:00")).arg(_hPosterior.toString("hh:mm:00"));
    mQuery->setQuery(query,QSqlDatabase::database());

    qDebug() << _nextChange << _hPosterior << _hAnterior;
    qDebug() << query;
    QSortFilterProxyModel::setSourceModel(_modeloBase);
    endResetModel();

    if(_modeloBase->rowCount())
        return true;
    return false;
}
