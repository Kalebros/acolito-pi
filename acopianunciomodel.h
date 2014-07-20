#ifndef ACOPIANUNCIOMODEL_H
#define ACOPIANUNCIOMODEL_H

#include <QAbstractListModel>
#include <QString>
#include <QList>
#include <QStringList>
#include <QDir>
#include <QFileInfo>

/*!
 * Modelo base para la lista de anuncios
 */

class AcoPiAnuncioModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit AcoPiAnuncioModel(QObject *parent = 0,QString path=QString());

    /*!
     * Establece la ruta que el modelo debe de vigilar
     * @param path  Ruta absoluta a vigilar
     * @note Modifica el objeto
     */
    void setPath(const QString path);

    /*!
     * Devuelve la ruta que el modelo esta vigilando
     * @return Ruta absoluta que está vigilando el modelo
     * @note No modifica el objeto
     */
    QString getPath() const;

    Q_INVOKABLE int rowCount(const QModelIndex &parent=QModelIndex()) const;
    Q_INVOKABLE QVariant data(const QModelIndex &index,int role=Qt::DisplayRole) const;

    /*!
      Recarga la lista de anuncios de la ruta
      @note Modifica el objeto
      */

    Q_INVOKABLE void reloadModel();

signals:

public slots:

private:

    QString _path;              ///< Ruta que vigila el modelo
    QStringList _listaAnuncios; ///< Lista de anuncios del modelo
    QStringList _filtros;       ///< Lista de filtros para archivos de imagen
};

#endif // ACOPIANUNCIOMODEL_H
