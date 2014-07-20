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
#include <QStringList>
#include <QStringListModel>
#include <QDir>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

#include "qmlmodelointermedio.h"
#include "acopiconfiguracion.h"
#include "acopianunciomodel.h"

/*!
 * Crea la configuracion a partir de un archivo JSON
 */

void buildConfiguracionJSON(AcoPiConfiguracion &cObject)
{
    QFileInfo infoConfig("config.json");
    if(!infoConfig.exists()) {
        qDebug() << "No existe archivo de configuracion, cargando configuracion por defecto...";
        cObject.setModoAcolito(AcoPiConfiguracion::Actividad);
        cObject.setModoOperacion(AcoPiConfiguracion::Depuracion);
        cObject.setItemContainerMargins(0);
        qDebug() << "Configuracion READY!";
        return;
    }

    QFile fileConfig(infoConfig.absoluteFilePath());
    if(!fileConfig.open(QFile::Text | QFile::ReadOnly)) {
        qDebug() << "No se pudo abrir el archivo, cargando configuracion por defecto...";
        cObject.setModoAcolito(AcoPiConfiguracion::Actividad);
        cObject.setModoOperacion(AcoPiConfiguracion::Depuracion);
        cObject.setItemContainerMargins(0);
        qDebug() << "Configuracion READY!";
        return;
    }

    QJsonObject data=QJsonDocument::fromJson(fileConfig.readAll()).object();

    if(data.contains("debug_mode")) {
        if(data.value("debug_mode").toBool()) {
            cObject.setModoOperacion(AcoPiConfiguracion::Depuracion);
        }
        else cObject.setModoOperacion(AcoPiConfiguracion::Database);
    } else cObject.setModoOperacion(AcoPiConfiguracion::Depuracion);

    if(data.value("modo").toString()=="ACTIVIDAD")
        cObject.setModoAcolito(AcoPiConfiguracion::Actividad);
    if(data.value("modo").toString()=="ANUNCIOS")
        cObject.setModoAcolito(AcoPiConfiguracion::Anuncios);

    cObject.setDatabaseHost(data.value("database").toObject().value("host").toString());
    cObject.setDatabaseUser(data.value("database").toObject().value("user").toString());
    cObject.setDatabasePass(data.value("database").toObject().value("password").toString());
    cObject.setDatabasePort(data.value("database").toObject().value("port").toDouble());
    cObject.setDatabaseSchema(data.value("database").toObject().value("schema").toString());
    cObject.setPathAnuncios(data.value("path_modo_anuncio").toString());
    cObject.setItemContainerMargins(data.value("item_container_margins").toDouble());
    qDebug() << "Configuracion READY!";
}

/*!
 * Crea el modelo de depuracion
 */

QAbstractItemModel *modeloDepuracion()
{
    QStandardItemModel *modelo=new QStandardItemModel(qApp);

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

    return modelo;
}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    //Cargar configuracion
    AcoPiConfiguracion configuracion;

    buildConfiguracionJSON(configuracion);

    QQmlApplicationEngine engine;

    QmlModeloIntermedio *mIntermedio=0;
    AcoPiAnuncioModel *mAnuncios=0;

    //Cargar datos de configuracion
    if(configuracion.modoOperacion()==AcoPiConfiguracion::Depuracion) {
        //Preparar modelo intermedio
        mIntermedio=new QmlModeloIntermedio(modeloDepuracion(),&app);
        engine.rootContext()->setContextProperty("modeloAct",mIntermedio);
    }
    else {
        qDebug() << "Modo de operacion aún no soportado.";
        exit(0);
    }

    engine.rootContext()->setContextProperty("item_container_margins",configuracion.itemContainerMargins());

    AcoPiConfiguracion::ModoAcolito mode=configuracion.modoAcolito();

    switch(mode)
    {
    case AcoPiConfiguracion::Actividad:
        engine.load(QUrl(QStringLiteral("qrc:///main.qml")));
        break;
    case AcoPiConfiguracion::Anuncios:
        mAnuncios=new AcoPiAnuncioModel(&app,configuracion.pathAnuncios());
        engine.rootContext()->setContextProperty("modeloAnuncio",mAnuncios);
        engine.load(QUrl(QStringLiteral("qrc:///mainAnuncio.qml")));
        break;
    default:
        qDebug() << "Modo no soportado.";
        exit(0);
        break;
    }

    //Es posible que necesite este hack para que funcione en la raspberry
    app.allWindows().first()->showFullScreen();
    return app.exec();
}
