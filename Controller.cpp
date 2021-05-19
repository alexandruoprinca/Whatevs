//
// Created by Todea  Catalin on 04.04.2021.
//

#include "Controller.h"
#include <iostream>

using namespace std;

Controller::Controller(Repository &repo) : repo{repo} {}


void Controller::addCoat(int size, string colour, string photo, float price, int quantity) {
    TrenchCoat elemToAdd(size, colour, photo, price, quantity);
    if (!repo.checkExistence(elemToAdd)) {
        this->repo.addElement(elemToAdd);
    }
}

void Controller::delCoat(int index) {
    try {
        this->repo.del(index);
    } catch (...) {
        cout << "Out of range\n";
    }
}

void Controller::updateCoat(int size, string colour, string photo, float price, int quantity, int index) {
    TrenchCoat elemToAdd(size, colour, photo, price, quantity);
    if (quantity == 0) {
        this->delCoat(index);
    } else {
        this->repo.update(elemToAdd, index);
    }
}

QString Controller::printAll() {
    QString stringToReturn{};

    std::vector<TrenchCoat> list = repo.getList();
    for (auto i : list) {
        stringToReturn += i.toString();
        stringToReturn += "\n";
    }

    return stringToReturn;
}

std::vector<TrenchCoat>& Controller::getList()
{
    return repo.getList();
}

void Controller::openFile() {
    repo.openFile();
}
