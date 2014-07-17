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


///*****************************************************************///
// IMPORTANTE: Para lanzar la aplicacion en una Raspberry Pi,
// es necesario especificar que utilize el plugin eglfs, ya que
// por defecto siempre intenta usar el xcb y en la raspberry falla.
// Para especificar el plugin, utilizar la opcion '-platform eglfs'
// al lanzar la aplicacion
///*****************************************************************///


#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QStandardItemModel>
#include <QList>
#include <QStandardItem>
#include <QDebug>
#include <QWindow>
#include <QWindowList>
#include <QFile>
#include <QFileInfo>


#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

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
    fila.append(new QStandardItem("Lorem fistrum ese pedazo de condemor condemor. Hasta luego Lucas diodenoo llevame al sircoo tiene musho peligro tiene musho peligro llevame al sircoo se calle ustée. Ese que llega torpedo torpedo pupita. No te digo trigo por no llamarte Rodrigor se calle ustée benemeritaar fistro pupita va usté muy cargadoo diodeno me cago en tus muelas qué dise usteer al ataquerl. Te va a hasé pupitaa sexuarl amatomaa a wan."));
    fila.append(new QStandardItem("Jueves"));
    fila.append(new QStandardItem("2"));
    fila.append(new QStandardItem("20"));
    fila.append(new QStandardItem("Sin definir"));
    fila.append(new QStandardItem("Lorem fistrum ese pedazo de condemor condemor. Hasta luego Lucas diodenoo llevame al sircoo tiene musho peligro tiene musho peligro llevame al sircoo se calle ustée. Ese que llega torpedo torpedo pupita. No te digo trigo por no llamarte Rodrigor se calle ustée benemeritaar fistro pupita va usté muy cargadoo diodeno me cago en tus muelas qué dise usteer al ataquerl. Te va a hasé pupitaa sexuarl amatomaa a wan."));

    modelo->appendRow(fila);

    fila.clear();

    fila.append(new QStandardItem("Actividad 2"));
    fila.append(new QStandardItem("Rol en vivo"));
    fila.append(new QStandardItem("17:00"));
    fila.append(new QStandardItem("18:00"));
    fila.append(new QStandardItem("Lorem fistrum ese pedazo de condemor condemor. Hasta luego Lucas diodenoo llevame al sircoo tiene musho peligro tiene musho peligro llevame al sircoo se calle ustée. Ese que llega torpedo torpedo pupita. No te digo trigo por no llamarte Rodrigor se calle ustée benemeritaar fistro pupita va usté muy cargadoo diodeno me cago en tus muelas qué dise usteer al ataquerl. Te va a hasé pupitaa sexuarl amatomaa a wan."));
    fila.append(new QStandardItem("Jueves"));
    fila.append(new QStandardItem("2"));
    fila.append(new QStandardItem("20"));
    fila.append(new QStandardItem("Sin definir"));
    fila.append(new QStandardItem("Lorem fistrum ese pedazo de condemor condemor. Hasta luego Lucas diodenoo llevame al sircoo tiene musho peligro tiene musho peligro llevame al sircoo se calle ustée. Ese que llega torpedo torpedo pupita. No te digo trigo por no llamarte Rodrigor se calle ustée benemeritaar fistro pupita va usté muy cargadoo diodeno me cago en tus muelas qué dise usteer al ataquerl. Te va a hasé pupitaa sexuarl amatomaa a wan."));

    modelo->appendRow(fila);

    modelo->setHeaderData(0,Qt::Horizontal,"nombre");
    modelo->setHeaderData(1,Qt::Horizontal,"tipo");
    modelo->setHeaderData(2,Qt::Horizontal,"hInicio");
    modelo->setHeaderData(3,Qt::Horizontal,"hFin");
    modelo->setHeaderData(4,Qt::Horizontal,"descripcion");
    modelo->setHeaderData(5,Qt::Horizontal,"dia");
    modelo->setHeaderData(6,Qt::Horizontal,"minParticipantes");
    modelo->setHeaderData(7,Qt::Horizontal,"maxParticipantes");
    modelo->setHeaderData(8,Qt::Horizontal,"lugar");
    modelo->setHeaderData(9,Qt::Horizontal,"requisitos");

    fila.clear();

    fila.append(new QStandardItem("Actividad 3"));
    fila.append(new QStandardItem("Talleres"));
    fila.append(new QStandardItem("21:00"));
    fila.append(new QStandardItem("22:00"));
    fila.append(new QStandardItem("Lorem fistrum ese pedazo de condemor condemor. Hasta luego Lucas diodenoo llevame al sircoo tiene musho peligro tiene musho peligro llevame al sircoo se calle ustée. Ese que llega torpedo torpedo pupita. No te digo trigo por no llamarte Rodrigor se calle ustée benemeritaar fistro pupita va usté muy cargadoo diodeno me cago en tus muelas qué dise usteer al ataquerl. Te va a hasé pupitaa sexuarl amatomaa a wan."));
    fila.append(new QStandardItem("Jueves"));
    fila.append(new QStandardItem("2"));
    fila.append(new QStandardItem("20"));
    fila.append(new QStandardItem("Sin definir"));
    fila.append(new QStandardItem("Lorem fistrum ese pedazo de condemor condemor. Hasta luego Lucas diodenoo llevame al sircoo tiene musho peligro tiene musho peligro llevame al sircoo se calle ustée. Ese que llega torpedo torpedo pupita. No te digo trigo por no llamarte Rodrigor se calle ustée benemeritaar fistro pupita va usté muy cargadoo diodeno me cago en tus muelas qué dise usteer al ataquerl. Te va a hasé pupitaa sexuarl amatomaa a wan."));

    modelo->appendRow(fila);

    fila.clear();

    fila.append(new QStandardItem("Actividad 4"));
    fila.append(new QStandardItem("Wargammes"));
    fila.append(new QStandardItem("17:00"));
    fila.append(new QStandardItem("19:00"));
    fila.append(new QStandardItem("Lorem fistrum ese pedazo de condemor condemor. Hasta luego Lucas diodenoo llevame al sircoo tiene musho peligro tiene musho peligro llevame al sircoo se calle ustée. Ese que llega torpedo torpedo pupita. No te digo trigo por no llamarte Rodrigor se calle ustée benemeritaar fistro pupita va usté muy cargadoo diodeno me cago en tus muelas qué dise usteer al ataquerl. Te va a hasé pupitaa sexuarl amatomaa a wan."));
    fila.append(new QStandardItem("Jueves"));
    fila.append(new QStandardItem("2"));
    fila.append(new QStandardItem("20"));
    fila.append(new QStandardItem("Sin definir"));
    fila.append(new QStandardItem("Lorem fistrum ese pedazo de condemor condemor. Hasta luego Lucas diodenoo llevame al sircoo tiene musho peligro tiene musho peligro llevame al sircoo se calle ustée. Ese que llega torpedo torpedo pupita. No te digo trigo por no llamarte Rodrigor se calle ustée benemeritaar fistro pupita va usté muy cargadoo diodeno me cago en tus muelas qué dise usteer al ataquerl. Te va a hasé pupitaa sexuarl amatomaa a wan."));

    modelo->appendRow(fila);

    fila.clear();

    fila.append(new QStandardItem("Actividad 5"));
    fila.append(new QStandardItem("Rol en mesa"));
    fila.append(new QStandardItem("17:00"));
    fila.append(new QStandardItem("19:00"));
    fila.append(new QStandardItem("Lorem fistrum ese pedazo de condemor condemor. Hasta luego Lucas diodenoo llevame al sircoo tiene musho peligro tiene musho peligro llevame al sircoo se calle ustée. Ese que llega torpedo torpedo pupita. No te digo trigo por no llamarte Rodrigor se calle ustée benemeritaar fistro pupita va usté muy cargadoo diodeno me cago en tus muelas qué dise usteer al ataquerl. Te va a hasé pupitaa sexuarl amatomaa a wan."));
    fila.append(new QStandardItem("Jueves"));
    fila.append(new QStandardItem("2"));
    fila.append(new QStandardItem("20"));
    fila.append(new QStandardItem("Sin definir"));
    fila.append(new QStandardItem("Lorem fistrum ese pedazo de condemor condemor. Hasta luego Lucas diodenoo llevame al sircoo tiene musho peligro tiene musho peligro llevame al sircoo se calle ustée. Ese que llega torpedo torpedo pupita. No te digo trigo por no llamarte Rodrigor se calle ustée benemeritaar fistro pupita va usté muy cargadoo diodeno me cago en tus muelas qué dise usteer al ataquerl. Te va a hasé pupitaa sexuarl amatomaa a wan."));

    modelo->appendRow(fila);

    fila.clear();

    fila.append(new QStandardItem("Actividad 6"));
    fila.append(new QStandardItem("Rol en vivo"));
    fila.append(new QStandardItem("17:00"));
    fila.append(new QStandardItem("19:00"));
    fila.append(new QStandardItem("Lorem fistrum ese pedazo de condemor condemor. Hasta luego Lucas diodenoo llevame al sircoo tiene musho peligro tiene musho peligro llevame al sircoo se calle ustée. Ese que llega torpedo torpedo pupita. No te digo trigo por no llamarte Rodrigor se calle ustée benemeritaar fistro pupita va usté muy cargadoo diodeno me cago en tus muelas qué dise usteer al ataquerl. Te va a hasé pupitaa sexuarl amatomaa a wan."));
    fila.append(new QStandardItem("Jueves"));
    fila.append(new QStandardItem("2"));
    fila.append(new QStandardItem("20"));
    fila.append(new QStandardItem("Sin definir"));
    fila.append(new QStandardItem("Lorem fistrum ese pedazo de condemor condemor. Hasta luego Lucas diodenoo llevame al sircoo tiene musho peligro tiene musho peligro llevame al sircoo se calle ustée. Ese que llega torpedo torpedo pupita. No te digo trigo por no llamarte Rodrigor se calle ustée benemeritaar fistro pupita va usté muy cargadoo diodeno me cago en tus muelas qué dise usteer al ataquerl. Te va a hasé pupitaa sexuarl amatomaa a wan."));

    modelo->appendRow(fila);

    fila.clear();

    fila.append(new QStandardItem("Actividad 7"));
    fila.append(new QStandardItem("Juegos de mesa o cartas"));
    fila.append(new QStandardItem("17:00"));
    fila.append(new QStandardItem("19:00"));
    fila.append(new QStandardItem("Lorem fistrum ese pedazo de condemor condemor. Hasta luego Lucas diodenoo llevame al sircoo tiene musho peligro tiene musho peligro llevame al sircoo se calle ustée. Ese que llega torpedo torpedo pupita. No te digo trigo por no llamarte Rodrigor se calle ustée benemeritaar fistro pupita va usté muy cargadoo diodeno me cago en tus muelas qué dise usteer al ataquerl. Te va a hasé pupitaa sexuarl amatomaa a wan."));
    fila.append(new QStandardItem("Domingo"));
    fila.append(new QStandardItem("2"));
    fila.append(new QStandardItem("20"));
    fila.append(new QStandardItem("Sin definir"));
    fila.append(new QStandardItem("Lorem fistrum ese pedazo de condemor condemor. Hasta luego Lucas diodenoo llevame al sircoo tiene musho peligro tiene musho peligro llevame al sircoo se calle ustée. Ese que llega torpedo torpedo pupita. No te digo trigo por no llamarte Rodrigor se calle ustée benemeritaar fistro pupita va usté muy cargadoo diodeno me cago en tus muelas qué dise usteer al ataquerl. Te va a hasé pupitaa sexuarl amatomaa a wan."));

    modelo->appendRow(fila);

    fila.clear();

    fila.append(new QStandardItem("Actividad 8"));
    fila.append(new QStandardItem("Rol en mesa"));
    fila.append(new QStandardItem("17:00"));
    fila.append(new QStandardItem("19:00"));
    fila.append(new QStandardItem("Lorem fistrum ese pedazo de condemor condemor. Hasta luego Lucas diodenoo llevame al sircoo tiene musho peligro tiene musho peligro llevame al sircoo se calle ustée. Ese que llega torpedo torpedo pupita. No te digo trigo por no llamarte Rodrigor se calle ustée benemeritaar fistro pupita va usté muy cargadoo diodeno me cago en tus muelas qué dise usteer al ataquerl. Te va a hasé pupitaa sexuarl amatomaa a wan."));
    fila.append(new QStandardItem("Sábado"));
    fila.append(new QStandardItem("2"));
    fila.append(new QStandardItem("20"));
    fila.append(new QStandardItem("Sin definir"));
    fila.append(new QStandardItem("Lorem fistrum ese pedazo de condemor condemor. Hasta luego Lucas diodenoo llevame al sircoo tiene musho peligro tiene musho peligro llevame al sircoo se calle ustée. Ese que llega torpedo torpedo pupita. No te digo trigo por no llamarte Rodrigor se calle ustée benemeritaar fistro pupita va usté muy cargadoo diodeno me cago en tus muelas qué dise usteer al ataquerl. Te va a hasé pupitaa sexuarl amatomaa a wan."));

    modelo->appendRow(fila);

    fila.clear();

    fila.append(new QStandardItem("Actividad 9"));
    fila.append(new QStandardItem("Rol en mesa"));
    fila.append(new QStandardItem("17:00"));
    fila.append(new QStandardItem("19:00"));
    fila.append(new QStandardItem("Lorem fistrum ese pedazo de condemor condemor. Hasta luego Lucas diodenoo llevame al sircoo tiene musho peligro tiene musho peligro llevame al sircoo se calle ustée. Ese que llega torpedo torpedo pupita. No te digo trigo por no llamarte Rodrigor se calle ustée benemeritaar fistro pupita va usté muy cargadoo diodeno me cago en tus muelas qué dise usteer al ataquerl. Te va a hasé pupitaa sexuarl amatomaa a wan."));
    fila.append(new QStandardItem("Jueves"));
    fila.append(new QStandardItem("2"));
    fila.append(new QStandardItem("20"));
    fila.append(new QStandardItem("Sin definir"));
    fila.append(new QStandardItem("Lorem fistrum ese pedazo de condemor condemor. Hasta luego Lucas diodenoo llevame al sircoo tiene musho peligro tiene musho peligro llevame al sircoo se calle ustée. Ese que llega torpedo torpedo pupita. No te digo trigo por no llamarte Rodrigor se calle ustée benemeritaar fistro pupita va usté muy cargadoo diodeno me cago en tus muelas qué dise usteer al ataquerl. Te va a hasé pupitaa sexuarl amatomaa a wan."));

    modelo->appendRow(fila);

    fila.clear();

    fila.append(new QStandardItem("Actividad 10"));
    fila.append(new QStandardItem("Rol en mesa"));
    fila.append(new QStandardItem("17:00"));
    fila.append(new QStandardItem("19:00"));
    fila.append(new QStandardItem("Lorem fistrum ese pedazo de condemor condemor. Hasta luego Lucas diodenoo llevame al sircoo tiene musho peligro tiene musho peligro llevame al sircoo se calle ustée. Ese que llega torpedo torpedo pupita. No te digo trigo por no llamarte Rodrigor se calle ustée benemeritaar fistro pupita va usté muy cargadoo diodeno me cago en tus muelas qué dise usteer al ataquerl. Te va a hasé pupitaa sexuarl amatomaa a wan."));
    fila.append(new QStandardItem("Viernes"));
    fila.append(new QStandardItem("2"));
    fila.append(new QStandardItem("20"));
    fila.append(new QStandardItem("Sin definir"));
    fila.append(new QStandardItem("Lorem fistrum ese pedazo de condemor condemor. Hasta luego Lucas diodenoo llevame al sircoo tiene musho peligro tiene musho peligro llevame al sircoo se calle ustée. Ese que llega torpedo torpedo pupita. No te digo trigo por no llamarte Rodrigor se calle ustée benemeritaar fistro pupita va usté muy cargadoo diodeno me cago en tus muelas qué dise usteer al ataquerl. Te va a hasé pupitaa sexuarl amatomaa a wan."));

    modelo->appendRow(fila);


    //Preparar modelo intermedio
    QmlModeloIntermedio *mIntermedio=new QmlModeloIntermedio(modelo,&app);

    QQmlApplicationEngine engine;

    //Cargar datos de configuracion

    //Mejor utilizo una clase para esto, queda más limpio
    if(!QFileInfo::exists("config.json")) {
        qDebug() << "Archivo de configuracion: NOT FOUND" << endl << "Cargando configuracion DEBUG... LISTO!";
        engine.rootContext()->setContextProperty("item_container_margins","0");
        engine.rootContext()->setContextProperty("modeloAct",mIntermedio);
        engine.load(QUrl(QStringLiteral("qrc:///main.qml")));
    } else {
        qDebug() << "Archivo de configuracion: config.json";
        QFile config("config.json");
        if(!config.open(QFile::Text | QFile::ReadOnly))
        {
            qDebug() << "Abriendo archivo... ERROR"<< endl << "Cargando configuracion DEBUG... LISTO!";
                        engine.rootContext()->setContextProperty("item_container_margins","0");
                        engine.rootContext()->setContextProperty("modeloAct",mIntermedio);
                        engine.load(QUrl(QStringLiteral("qrc:///main.qml")));
        } else {
            QJsonObject objConfig=QJsonDocument::fromJson(config.readAll()).object();
            if(objConfig.value("debug_mode").toBool()) {
                qDebug() << "Modo DEBUG, cargando modelo de depuracion... LISTO!";
                engine.rootContext()->setContextProperty("modeloAct",mIntermedio);
            }
            qDebug() << "item_container_margins: " << objConfig.value("item_container_margins").toDouble();
            engine.rootContext()->setContextProperty("item_container_margins",objConfig.value("item_container_margins").toDouble());
            qDebug() << "Modo de trabajo: " << objConfig.value("modo").toString() <<endl;
            engine.load(QUrl(QStringLiteral("qrc:///main.qml")));
        }
    }

    //Es posible que necesite este hack para que funcione en la raspberry
    app.allWindows().first()->showFullScreen();
    return app.exec();
}
