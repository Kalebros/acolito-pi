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

    double descripcionFontSize() const
    { return _descripcionFontSize; }

    double requisitosFontSize() const
    { return _requisitosFontSize; }

    double clockDriftHour() const
    { return _clockDrift_hour; }

    void setModoOperacion(ModoAcceso m);
    void setModoAcolito(ModoAcolito m);
    void setDatabaseUser(QString user);
    void setDatabasePass(QString pass);
    void setDatabaseHost(QString host);
    void setDatabaseSchema(QString schema);
    void setDatabasePort(int port);
    void setItemContainerMargins(double d);
    void setIndexTimerInterval(double i);
    void setDescripcionFontSize(double d);
    void setRequisitosFontSize(double d);
    void setClockDriftHour(double d);

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
    double _descripcionFontSize;
    double _requisitosFontSize;
    double _clockDrift_hour;

    QString _pathAnuncios;
};

#endif // ACOPICONFIGURACION_H
