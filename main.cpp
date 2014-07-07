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

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QStandardItemModel>
#include <QList>
#include <QStandardItem>
#include <QDebug>

#include "qmlmodelointermedio.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    //Crear modelo de depuracion

    QStandardItemModel *modelo=new QStandardItemModel(&app);

    QList<QStandardItem*> fila;

    fila.append(new QStandardItem("Actividad con nombre jodidamente largo"));
    fila.append(new QStandardItem("Rol en mesa"));
    fila.append(new QStandardItem("16:00"));
    fila.append(new QStandardItem("19:00"));
    fila.append(new QStandardItem("Descripcion de la actividad"));

    modelo->appendRow(fila);

    fila.clear();

    fila.append(new QStandardItem("Actividad 2"));
    fila.append(new QStandardItem("Rol en vivo"));
    fila.append(new QStandardItem("17:00"));
    fila.append(new QStandardItem("18:00"));
    fila.append(new QStandardItem("Descripcion de la actividad"));

    modelo->appendRow(fila);

    modelo->setHeaderData(0,Qt::Horizontal,"nombre");
    modelo->setHeaderData(1,Qt::Horizontal,"tipo");
    modelo->setHeaderData(2,Qt::Horizontal,"hInicio");
    modelo->setHeaderData(3,Qt::Horizontal,"hFin");
    modelo->setHeaderData(4,Qt::Horizontal,"descripcion");

    fila.clear();

    fila.append(new QStandardItem("Actividad 3"));
    fila.append(new QStandardItem("Talleres"));
    fila.append(new QStandardItem("21:00"));
    fila.append(new QStandardItem("22:00"));
    fila.append(new QStandardItem("Descripcion de la actividad"));

    modelo->appendRow(fila);

    fila.clear();

    fila.append(new QStandardItem("Actividad 4"));
    fila.append(new QStandardItem("Wargammes"));
    fila.append(new QStandardItem("17:00"));
    fila.append(new QStandardItem("19:00"));
    fila.append(new QStandardItem("Descripcion de la actividad"));

    modelo->appendRow(fila);

    fila.clear();

    fila.append(new QStandardItem("Actividad 5"));
    fila.append(new QStandardItem("Rol en mesa"));
    fila.append(new QStandardItem("17:00"));
    fila.append(new QStandardItem("19:00"));
    fila.append(new QStandardItem("Descripcion de la actividad"));

    modelo->appendRow(fila);

    fila.clear();

    fila.append(new QStandardItem("Actividad 6"));
    fila.append(new QStandardItem("Rol en vivo"));
    fila.append(new QStandardItem("17:00"));
    fila.append(new QStandardItem("19:00"));
    fila.append(new QStandardItem("Descripcion de la actividad"));

    modelo->appendRow(fila);

    fila.clear();

    fila.append(new QStandardItem("Actividad 7"));
    fila.append(new QStandardItem("Rol en mesa"));
    fila.append(new QStandardItem("17:00"));
    fila.append(new QStandardItem("19:00"));
    fila.append(new QStandardItem("Descripcion de la actividad"));

    modelo->appendRow(fila);

    fila.clear();

    fila.append(new QStandardItem("Actividad 8"));
    fila.append(new QStandardItem("Rol en mesa"));
    fila.append(new QStandardItem("17:00"));
    fila.append(new QStandardItem("19:00"));
    fila.append(new QStandardItem("Descripcion de la actividad"));

    modelo->appendRow(fila);

    fila.clear();

    fila.append(new QStandardItem("Actividad 9"));
    fila.append(new QStandardItem("Rol en mesa"));
    fila.append(new QStandardItem("17:00"));
    fila.append(new QStandardItem("19:00"));
    fila.append(new QStandardItem("Descripcion de la actividad"));

    modelo->appendRow(fila);

    fila.clear();

    fila.append(new QStandardItem("Actividad 10"));
    fila.append(new QStandardItem("Rol en mesa"));
    fila.append(new QStandardItem("17:00"));
    fila.append(new QStandardItem("19:00"));
    fila.append(new QStandardItem("Descripcion de la actividad"));

    modelo->appendRow(fila);

    //Preparar modelo intermedio
    QmlModeloIntermedio *mIntermedio=new QmlModeloIntermedio(modelo,&app);

    qDebug() << mIntermedio->roleNames();

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("modeloAct",mIntermedio);

    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
