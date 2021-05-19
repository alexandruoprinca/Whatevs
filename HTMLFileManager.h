//
// Created by Todea  Catalin on 26.04.2021.
//

#ifndef TCIE2431_LAB6_HTMLFILEMANAGER_H
#define TCIE2431_LAB6_HTMLFILEMANAGER_H

#include <utility>

#include "FileManager.h"

class HTMLFileManager: public FileManager {
public:
    HTMLFileManager(string fileName): FileManager(std::move(fileName)) {};
    void writeToFile(vector<TrenchCoat>) override;
    vector<TrenchCoat> readFromFile() override;
    void open() override;
};


#endif //TCIE2431_LAB6_HTMLFILEMANAGER_H
