#ifndef MODEL_H
#define MODEL_H
#include <QAbstractItemModel>
#include <QVector>
#include "TrenchCoat.h"

class Model : public QAbstractTableModel
{
    Q_OBJECT
public:
    Model(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
private:
    void populateModel();
    QVector<TrenchCoat> modelData{};
};
#endif // MODEL_H
