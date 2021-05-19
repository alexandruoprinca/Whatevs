#include "Model.h"



Model::Model(Controller& controller,QObject *parent)
{
    populateModel(controller);
}

int Model::rowCount(const QModelIndex &parent) const
{
    return modelData.size();
}

int Model::columnCount(const QModelIndex &parent) const
{
 return 1;
}

QVariant Model::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole){
        QVariant variant;
        variant.setValue(modelData[index.row()]);
        return variant;
    }
    return QString{};
}

void Model::populateModel(Controller& controller)
{
    auto val = controller.getList();
    for(auto i : val){
        modelData.push_back(i);
    }
}
