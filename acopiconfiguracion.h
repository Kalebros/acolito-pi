#ifndef ACOPICONFIGURACION_H
#define ACOPICONFIGURACION_H

#include <QString>

/*!
 * Clase que contiene la configuracion básica de AcolitoPi
 */

class AcoPiConfiguracion
{
public:

    enum ModoAcolito
    { Actividad=0,Anuncios };

    enum ModoAcceso {
        Depuracion=0,Database
    };

    explicit AcoPiConfiguracion(ModoAcceso operacion=Depuracion,ModoAcolito acolito=Actividad);

    ~AcoPiConfiguracion();

    ModoAcceso modoOperacion() const
    { return _operacion; }

    ModoAcolito modoAcolito() const
    { return _modoAcolito; }

    QString databaseUser() const
    { return _dbUser; }

    QString databasePassword() const
    { return _dbPass; }

    QString databaseHost() const
    { return _dbHost; }

    int databasePort() const
    { return _dbPort; }

    QString databaseSchema() const
    { return _dbSchema; }

    QString pathAnuncios() const
    { return _pathAnuncios; }

    double itemContainerMargins() const
    { return _margins; }

    double indexTimerInterval() const
    { return _indexTimer_interval; }

    void setModoOperacion(ModoAcceso m);
    void setModoAcolito(ModoAcolito m);
    void setDatabaseUser(QString user);
    void setDatabasePass(QString pass);
    void setDatabaseHost(QString host);
    void setDatabaseSchema(QString schema);
    void setDatabasePort(int port);
    void setItemContainerMargins(double d);
    void setIndexTimerInterval(double i);

    void setPathAnuncios(QString p);

private:

    ModoAcceso _operacion;
    ModoAcolito _modoAcolito;

    QString _dbUser;
    QString _dbPass;
    QString _dbHost;
    QString _dbSchema;
    int _dbPort;
    double _margins;
    double _indexTimer_interval;

    QString _pathAnuncios;
};

#endif // ACOPICONFIGURACION_H
