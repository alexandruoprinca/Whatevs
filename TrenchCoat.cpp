//
// Created by Todea  Catalin on 04.04.2021.
//

#include "TrenchCoat.h"
#include <iostream>

using namespace std;

//MARK:: - Life Cycle

TrenchCoat::TrenchCoat() {

}

TrenchCoat::TrenchCoat(int size, string colour, string photo, float price, int quantity) {
    this->size = size;
    this->colour = colour;
    this->photo = photo;
    this->price = price;
    this->quantity = quantity;
}

TrenchCoat::TrenchCoat(const TrenchCoat& elem) {
    this->size = elem.size;
    this->colour = elem.colour;
    this->photo = elem.photo;
    this->price = elem.price;
    this->quantity = elem.quantity;
}

//MARK:: - Getters

int TrenchCoat::getSize() const {
    return this->size;
}

string TrenchCoat::getPhoto() {
    return this->photo;
}

string TrenchCoat::getColour() {
    return this->colour;
}

float TrenchCoat::getPrice() {
    return this->price;
}

int TrenchCoat::getQuantity() {
    return this->quantity;
}

//MARK:: - Setters

void TrenchCoat::setSize(int size) {
    this->size = size;
}

void TrenchCoat::setPhoto(string photo) {
    this->photo = photo;
}

void TrenchCoat::setPrice(float price) {
    this->price = price;
}
void TrenchCoat::setColour(string colour) {
    this->colour = colour;
}

void TrenchCoat::setQuantity(int quantity) {
    this->quantity = quantity;
}

//MARK:: - Methodes

QString TrenchCoat::toString() const{

    string sizeString = to_string(this->size);
    string priceString = to_string(this->price);
    string quantityString = to_string(this->quantity);

    return QString("Size: ") + sizeString.c_str() +
           ", Color: " + this->colour.c_str() +
           ", price: " + priceString.c_str() +
           ", quantity: " + quantityString.c_str() +
           ", photo: " + this->photo.c_str() + "\n";
}

bool TrenchCoat::operator== (const TrenchCoat t) {
    return (t.size == this->size && t.colour == this->colour);
}

void TrenchCoat::addQuantity(int toAdd) {
    this->quantity += toAdd;
}

std::ostream& operator<<(ostream &os, TrenchCoat& tr) {
    os << tr.toString().constData();
    return os;
}

std::string TrenchCoat::toCSV() {
    string sizeString = to_string(this->size);
    string priceString = to_string(this->price);
    string quantityString = to_string(this->quantity);

    return "" + sizeString +
           "," + this->colour +
           "," + priceString +
           "," + quantityString +
           "," + this->photo + '\n';
}

std::string TrenchCoat::toHTML() {
    string sizeString = to_string(this->size);
    string priceString = to_string(this->price);
    string quantityString = to_string(this->quantity);

    return "<tr><td>" + sizeString +
           "</td><td>" + this->colour +
           "</td><td>" + priceString +
           "</td><td>" + quantityString +
           "</td><td>" + this->photo + "</td></tr>\n";
}
