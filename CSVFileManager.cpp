//
// Created by Todea  Catalin on 26.04.2021.
//

#include <iostream>
#include "CSVFileManager.h"



void CSVFileManager::writeToFile(vector<TrenchCoat> container) {
    std::ofstream file;
    file.open(fileName);
    for (auto i : container) {
        std::cout << i;
        file << i.toCSV();
    }
}

vector<TrenchCoat> CSVFileManager::readFromFile() {
    std::ifstream  file{fileName};
    std::string str{};
    std::string word = "";

    vector<TrenchCoat> container{};

    for (;std::getline(file, str) && (str != "");) {
        word = "";
        std::string size = "", colour = "", price = "", quantity = "", photo = "";
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == ',')
            {
                if (size == "") {
                    size = word;
                } else if (colour == "") {
                    colour = word;
                } else if (price == "") {
                    price = word;
                } else if (quantity == "") {
                    quantity = word;
                }
                word = "";
            }
            else {
                word = word + str[i];
            }
        }
        photo = word;
        if (price != "") {
            float floatPrice = std::stof(price);
            int intSize = std::stoi(size);
            int intQuantity = std::stoi(quantity);
            container.push_back(TrenchCoat(intSize, colour, photo, floatPrice, intQuantity));
        }
    }
    return container;
}

void CSVFileManager::open() {
    string str = "Open " + fileName;
    system(str.c_str());
}

