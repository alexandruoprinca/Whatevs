#ifndef MODEL_H
#define MODEL_H
#include <QAbstractItemModel>
#include <QVector>
#include "Controller.h"
#include "TrenchCoat.h"

class Model : public QAbstractTableModel
{
//TODEA: deocamdata clasa asta functioneaza afisand lista pentru admin, trebe modificata astfel incat daca esti Client si nu Admin sa afiseze un singur row
    Q_OBJECT
public:
    Model(Controller& controller, QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
private:
    void populateModel(Controller& controller);
    QVector<TrenchCoat> modelData{};
};
#endif // MODEL_H
