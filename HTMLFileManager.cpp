//
// Created by Todea  Catalin on 26.04.2021.
//

#include "HTMLFileManager.h"
#include <iostream>

using namespace std;

void HTMLFileManager::writeToFile(vector<TrenchCoat> container) {
    std::ofstream file;
    file.open(fileName);
    file << "<html><table>";
    for (auto i : container) {
        file << i.toHTML();
    }
    file << "</table></html>";
}

vector<TrenchCoat> HTMLFileManager::readFromFile() {
    std::ifstream  file{fileName};
    std::string str{};
    std::string word = "";

    vector<TrenchCoat> container{};

    bool inside = false;
    for (;std::getline(file, str) && (str != "");) {
        std::string size = "", colour = "", price = "", quantity = "", photo = "";
        for (char c : str) {
            if (c == '>') {
                inside = true;
            }
            else if (c == '<') {
                inside = false;
                if (word != "") {
                    if (size == "") {
                        size = word;
                    } else if (colour == "") {
                        colour = word;
                    } else if (price == "") {
                        price = word;
                    } else if (quantity == "") {
                        quantity = word;
                    } else if (photo == "") {
                        photo = word;
                    }
                    word = "";
                }
            }
            else if (inside)
                word += c;
        }
        if (price != "") {
            float floatPrice = std::stof(price);
            int intSize = std::stoi(size);
            int intQuantity = std::stoi(quantity);
            container.push_back(TrenchCoat(intSize, colour, photo, floatPrice, intQuantity));
        }
    }

    return container;
}

void HTMLFileManager::open() {
    string str = "Open " + fileName;
    system(str.c_str());
}
