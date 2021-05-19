//
// Created by Todea  Catalin on 04.04.2021.
//

#include "ClientController.h"
#include <iostream>
#include <vector>

using namespace std;

QString ClientController::currentCoatToString(int size) {
    return vector[currentCoat].toString();
}

void ClientController::nextCoat() {
    if (currentCoat < vector.size()) {
        currentCoat++;
    } else {
        currentCoat = 0;
    }
}

void ClientController::buyCoat() {
    if (vector[currentCoat].getQuantity() == 0) {
        cout << "Out of stock!\n";
        return;
    }

    vector[currentCoat].addQuantity(-1);
    //TODO fa si in repo sa traga din cantitate

    TrenchCoat coatBought = vector[currentCoat];
    coatBought.setQuantity(1);
    basket.addElement(coatBought);
}

QString ClientController::showBasket() {
    QString basket{};
    float total = 0;
    basket += "Your basket:\n";
    for (int i = 0; i < this->basket.getList().size(); i++) {
        basket += this->basket.getList()[i].toString();
        total += this->basket.getList()[i].getPrice();
    }
    basket += "\nTotal: ";
    basket += QString::number(total);
    return basket;
}

ClientController::ClientController(Repository &repo, Repository &bucket, int size): repo{repo}, basket{bucket} {
    vector.reserve(repo.getList().size());
    if (size == 0) {
        vector = repo.getList();
    } else {
        copy_if(repo.getList().begin(), repo.getList().end(), std::back_inserter(vector), [=] (const TrenchCoat &coat) { return coat.getSize() == size; });
//        vector = repo.getList();
//        for (int i = 0; i < vector.size(); i++) {
//            if (vector[i].getSize() != size) {
//                vector.erase(vector.);
//            }
//        }
    }
}
