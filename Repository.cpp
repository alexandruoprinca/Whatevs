//
// Created by Todea  Catalin on 04.04.2021.
//

#include "Repository.h"

void Repository::addElement(TrenchCoat& elem) {
    this->container.push_back(elem);
    writeToFile();
}

void Repository::update(TrenchCoat elem, int index) {
    this->container[index] = elem;
    writeToFile();
}

TrenchCoat Repository::getCoat(int index) {
    return this->container[index];
}

void Repository::del(int index) {
    if ((index < 0) || (index >= container.size())) {
        throw "Index Out of range!";
    } else {
        this->container.erase(container.begin() + index);
    }
    writeToFile();
}

std::vector<TrenchCoat>& Repository::getList() {
    readFromFile();
    return this->container;
}

bool Repository::checkExistence(TrenchCoat t1) {
    int index;
    for (index = 0; index < container.size(); index++) {
        if (container[index] == t1) {
            container[index].addQuantity(t1.getSize());
            return true;
        }
    }
    return false;
}

void Repository::writeToFile() {
    fileManager.writeToFile(container);
}

void Repository::readFromFile() {
    container = fileManager.readFromFile();
}

void Repository::openFile() {
    fileManager.open();
}

