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

#include "acopiconfiguracion.h"

AcoPiConfiguracion::AcoPiConfiguracion(ModoAcceso operacion,ModoAcolito acolito)
{
    _modoAcolito=acolito;
    _operacion=operacion;
    _dbPort=-1;
}

AcoPiConfiguracion::~AcoPiConfiguracion()
{

}

void AcoPiConfiguracion::setModoOperacion(ModoAcceso m)
{
    _operacion=m;
}

void AcoPiConfiguracion::setModoAcolito(ModoAcolito m)
{
    _modoAcolito=m;
}

void AcoPiConfiguracion::setDatabaseUser(QString user)
{
    _dbUser=user;
}

void AcoPiConfiguracion::setDatabasePass(QString pass)
{
    _dbPass=pass;
}

void AcoPiConfiguracion::setDatabaseHost(QString host)
{
    _dbHost=host;
}

void AcoPiConfiguracion::setDatabaseSchema(QString schema)
{
    _dbSchema=schema;
}

void AcoPiConfiguracion::setDatabasePort(int port)
{
    _dbPort=port;
}

void AcoPiConfiguracion::setPathAnuncios(QString p)
{
    _pathAnuncios=p;
}

void AcoPiConfiguracion::setItemContainerMargins(double d)
{
    _margins=d;
}

