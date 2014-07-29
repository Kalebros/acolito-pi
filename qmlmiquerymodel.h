#ifndef QMLMIQUERYMODEL_H
#define QMLMIQUERYMODEL_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>

#include "qmlmodelointermedio.h"

class QmlMIQueryModel : public QmlModeloIntermedio
{
    Q_OBJECT
public:
    explicit QmlMIQueryModel(QObject *parent = 0, QDate f=QDate(), QTime h=QTime());

    Q_INVOKABLE virtual bool reloadModelo();

signals:

public slots:

private:

    QString _internBasicQuery;   ///< Query interna del modelo
    QTime _nextChange;          ///< Hora para el siguiente cambio
    QTime _hAnterior;           ///< Extremo inferior del limite
    QTime _hPosterior;          ///< Extremo superior del limite

};

#endif // QMLMIQUERYMODEL_H
