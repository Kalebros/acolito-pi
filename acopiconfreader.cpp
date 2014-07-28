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

#include "acopiconfreader.h"

AcoPiConfReader::AcoPiConfReader()
{
}

AcoPiConfReader::~AcoPiConfReader()
{
}

void AcoPiConfReader::readJSONConfiguracion(AcoPiConfiguracion &c, Plataforma modo)
{
    QJsonObject data;
    if(modo==Windows) {
        QFileInfo infoConfig(qApp->applicationDirPath()+"/config.json");
        if(!infoConfig.exists()) {
            qDebug() << "No existe archivo de configuracion, cargando configuracion por defecto...";
            c.setModoAcolito(AcoPiConfiguracion::Actividad);
            c.setModoOperacion(AcoPiConfiguracion::Depuracion);
            c.setItemContainerMargins(0);
            qDebug() << "Configuracion READY!";
            return;
        }

        QFile fileConfig(infoConfig.absoluteFilePath());
        if(!fileConfig.open(QFile::Text | QFile::ReadOnly)) {
            qDebug() << "No se pudo abrir el archivo, cargando configuracion por defecto...";
            c.setModoAcolito(AcoPiConfiguracion::Actividad);
            c.setModoOperacion(AcoPiConfiguracion::Depuracion);
            c.setItemContainerMargins(0);
            qDebug() << "Configuracion READY!";
            return;
        }

        QString fileData=QString::fromUtf8(fileConfig.readAll());
        data=QJsonDocument::fromJson(fileData.toUtf8()).object();
    }
    if(modo==Raspberry) {
        QFileInfo infoConfig("config.json");
        if(!infoConfig.exists()) {
            qDebug() << "No existe archivo de configuracion, cargando configuracion por defecto...";
            c.setModoAcolito(AcoPiConfiguracion::Actividad);
            c.setModoOperacion(AcoPiConfiguracion::Depuracion);
            c.setItemContainerMargins(0);
            qDebug() << "Configuracion READY!";
            return;
        }

        QFile fileConfig(infoConfig.absoluteFilePath());
        if(!fileConfig.open(QFile::Text | QFile::ReadOnly)) {
            qDebug() << "No se pudo abrir el archivo, cargando configuracion por defecto...";
            c.setModoAcolito(AcoPiConfiguracion::Actividad);
            c.setModoOperacion(AcoPiConfiguracion::Depuracion);
            c.setItemContainerMargins(0);
            qDebug() << "Configuracion READY!";
            return;
        }

        data=QJsonDocument::fromJson(fileConfig.readAll()).object();
    }

    if(data.contains("debug_mode")) {
        if(data.value("debug_mode").toBool()) {
            c.setModoOperacion(AcoPiConfiguracion::Depuracion);
        }
        else c.setModoOperacion(AcoPiConfiguracion::Database);
    } else c.setModoOperacion(AcoPiConfiguracion::Database);

    if(data.value("modo").toString()=="ACTIVIDAD")
        c.setModoAcolito(AcoPiConfiguracion::Actividad);
    if(data.value("modo").toString()=="ANUNCIOS")
        c.setModoAcolito(AcoPiConfiguracion::Anuncios);

    c.setDatabaseHost(data.value("database").toObject().value("host").toString());
    c.setDatabaseUser(data.value("database").toObject().value("user").toString());
    c.setDatabasePass(data.value("database").toObject().value("password").toString());
    c.setDatabasePort(data.value("database").toObject().value("port").toDouble());
    c.setDatabaseSchema(data.value("database").toObject().value("schema").toString());
    c.setPathAnuncios(data.value("path_modo_anuncio").toString());
    c.setItemContainerMargins(data.value("item_container_margins").toDouble());
    c.setIndexTimerInterval(data.value("indexTimer_interval").toDouble());
    c.setDescripcionFontSize(data.value("fontSize_descripcion").toDouble());
    c.setRequisitosFontSize(data.value("fontSize_requisitos").toDouble());
    c.setClockDriftHour(data.value("clockDrift_hour").toDouble());
    qDebug() << "Configuracion READY!";

}
