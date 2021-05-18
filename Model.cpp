#include "Model.h"



Model::Model(QObject *parent)
{
    populateModel();
}

int Model::rowCount(const QModelIndex &parent) const
{
    return modelData.size();
}

int Model::columnCount(const QModelIndex &parent) const
{
 return 2;
}

QVariant Model::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole){
        QVariant variant;
        if(index.column() == 0)
            variant.setValue(modelData[index.row()].first);
        else
            variant.setValue(modelData[index.row()]);
        return variant;
    }
    return QString{};
}

void Model::populateModel()
{
    for(auto i = 0;i<10;i++){
        modelData.push_back(TrenchCoat{i});
    }
}
