//
// Created by Todea  Catalin on 26.04.2021.
//

#ifndef TCIE2431_LAB6_FILEMANAGER_H
#define TCIE2431_LAB6_FILEMANAGER_H

#include "TrenchCoat.h"
#include <string>
#include <utility>
#include <vector>
#include <fstream>

using namespace std;

class FileManager {
protected:
    string fileName;
    FileManager(string fileName): fileName{move(fileName)} {};
public:
    virtual void writeToFile(vector<TrenchCoat>) = 0;
    virtual vector<TrenchCoat> readFromFile() = 0;
    virtual void open() = 0;
};


#endif //TCIE2431_LAB6_FILEMANAGER_H
