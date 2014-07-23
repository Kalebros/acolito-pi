#ifndef ACOPICONFREADER_H
#define ACOPICONFREADER_H

#include <QCoreApplication>
#include <QFile>
#include <QFileInfo>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QDebug>

#include "acopiconfiguracion.h"

/*!
  Lector de configuraciones de un archivo JSON
 */

class AcoPiConfReader
{
public:

    enum Plataforma
    {
        Windows=0,Raspberry
    };

    AcoPiConfReader();
    ~AcoPiConfReader();

    void readJSONConfiguracion(AcoPiConfiguracion &c,Plataforma modo);
};

#endif // ACOPICONFREADER_H
