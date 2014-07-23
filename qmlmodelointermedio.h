#ifndef QMLMODELOINTERMEDIO_H
#define QMLMODELOINTERMEDIO_H

#include <QSortFilterProxyModel>
#include <QAbstractItemModel>
#include <QHash>
#include <QByteArray>
#include <QDate>
#include <QTime>
#include <QDateTime>

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

    /*!
      Establece el modelo base
      @param mBase  Modelo base a utilizar
      @note Modifica el objeto
     */
    void setModeloBase(QAbstractItemModel *mBase);

    /*!
      Devuelve si la fecha esta fija en el modelo o no
      @return bool, true: esta fija, false no lo está
      @note No modifica el objeto
     */
    bool isFechaFija() const;

    /*!
      Devuelve si la hora esta fija en el modelo o no
      @return bool, true: esta fija, false no lo esta
      @note No modifica el objeto
     */
    bool isHoraFija() const;

    /*!
      Establece o cambia la fecha fija del modelo
      @param fecha  Fecha fija del modelo
      @note Modifica el objeto
      @post Si existia una fecha fija, ahora se ha cambiado a la nueva
      fecha fija.
     */
    void setFechaFija(QDate fecha);

    /*!
      Devuelve la fecha fija del modelo
      @return QDate, fecha fija del modelo
      @note No modifica el objeto
      @post Si la fecha no esta fija, devuelve el ultimo valor fijado,
      así que es recomendable utilizar conjuntamente con isFechaFija
      */

    QDate getFechaFija() const;

    /*!
      Establece o cambia la hora fija del modelo
      @param hora   Hora fija del modelo
      @note Modifica el objeto
      @post Si existia una hora fija, ahora se ha cambiado a la nueva
      hora fija.
     */

    void setHoraFija(QTime hora);

    /*!
      Devuelve la hora fija del modelo
      @return QTime, hora fija del modelo
      @note No modifica el objeto
      @post Si la hora no esta fija, devuelve el ultimo valor fijado,
      asi que es recomendable utilizar conjuntamente con isHoraFija
      */

    QTime getHoraFija() const;

    /*!
      Desactiva la fecha fija
      @note Modifica el objeto
     */
    void unsetFechaFija();

    /*!
      Desactiva la hora fija
      @note Modifica el objeto
     */
    void unsetHoraFija();

signals:

public slots:

protected:

    QAbstractItemModel *_modeloBase;    ///< Modelo base de datos
    QDate _fechaFija;
    QTime _horaFija;
    bool _isFechaFija;
    bool _isHoraFija;
    QHash<int, QByteArray> _roleNames;

    /*!
      Genera la lista de roles para QML
      */

    void generateRoles();

};

#endif // QMLMODELOINTERMEDIO_H
