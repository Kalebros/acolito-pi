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

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>

#include "qmlmodelointermedio.h"
#include "qmlmiquerymodel.h"
#include "acopiconfiguracion.h"
#include "acopianunciomodel.h"
#include "acopiconfreader.h"

/*!
 * Crea el modelo de depuracion
 */

QAbstractItemModel *modeloDepuracion();

////////////////////////////////////////////////////////////////
/// MAIN
////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    //Cargar configuracion
    AcoPiConfiguracion configuracion;
    AcoPiConfReader readerConf;

    //Cambiar el modo según la plataforma
#ifdef WINDOWS_PLATFORM
    readerConf.readJSONConfiguracion(configuracion,AcoPiConfReader::Windows);
#elif LINUX_PLATFORM
    readerConf.readJSONConfiguracion(configuracion,AcoPiConfReader::Raspberry);
#endif

//    buildConfiguracionJSON(configuracion);

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
        //Creamos el modelo contra la base de datos y lo asociamos al modelo intermedio
        QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName(configuracion.databaseHost());
        db.setDatabaseName(configuracion.databaseSchema());
        db.setUserName(configuracion.databaseUser());
        db.setPassword(configuracion.databasePassword());
        db.setPort(configuracion.databasePort());

        if(!db.open())
        {
            qDebug() << "NO SE PUDO ABRIR LA BASE DE DATOS ESPECIFICADA.";
            qDebug() << db.lastError().text();
            qDebug() << "USER: " << configuracion.databaseUser() << ", PASS: "<< configuracion.databasePassword();
            exit(1);
        }
        //Crear modelo intermedio de base de datos
        QmlMIQueryModel *miActividad=new QmlMIQueryModel(&app);
        miActividad->setFechaFija(QDate(2013,8,2));
        miActividad->setHoraFija(QTime(17,0));
        engine.rootContext()->setContextProperty("modeloAct",miActividad);
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
