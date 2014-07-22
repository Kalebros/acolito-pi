#ifndef QMLMIQUERYMODEL_H
#define QMLMIQUERYMODEL_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>

#include "qmlmodelointermedio.h"

class QmlMIQueryModel : public QmlModeloIntermedio
{
    Q_OBJECT
public:
    explicit QmlMIQueryModel(QAbstractItemModel *mBase=0,QObject *parent = 0);

    Q_INVOKABLE virtual bool reloadModelo();

signals:

public slots:

};

#endif // QMLMIQUERYMODEL_H
