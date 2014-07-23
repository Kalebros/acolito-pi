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
    explicit QmlMIQueryModel(QObject *parent = 0);

    Q_INVOKABLE virtual bool reloadModelo();

signals:

public slots:

private:

    QString _internBasicQuery;   ///< Query interna del modelo

};

#endif // QMLMIQUERYMODEL_H
