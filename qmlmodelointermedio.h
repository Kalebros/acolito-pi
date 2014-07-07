#ifndef QMLMODELOINTERMEDIO_H
#define QMLMODELOINTERMEDIO_H

#include <QSortFilterProxyModel>
#include <QAbstractItemModel>
#include <QHash>
#include <QByteArray>

/*!
 * \brief Clase QmlModeloIntermedio
 *
 * Este modelo hace de enlace entre un modelo base de C++ y
 * la parte de QML de QtQuick
 */

class QmlModeloIntermedio : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit QmlModeloIntermedio(QAbstractItemModel *mBase=0,QObject *parent = 0);

    Q_INVOKABLE QVariant data(const QModelIndex &index, int role) const;

    /*!
      Recarga el modelo base del modelo intermedio de enlace

      @return bool, true: el modelo contiene datos, false: el modelo no contiene datos
      */

    Q_INVOKABLE virtual bool reloadModelo();

    Q_INVOKABLE QHash<int, QByteArray> roleNames() const
    { return _roleNames; }

    void setModeloBase(QAbstractItemModel *mBase);


signals:

public slots:

private:

    QAbstractItemModel *_modeloBase;    ///< Modelo base de datos
    QHash<int, QByteArray> _roleNames;

    /*!
      Genera la lista de roles para QML
      */

    void generateRoles();
};

#endif // QMLMODELOINTERMEDIO_H
