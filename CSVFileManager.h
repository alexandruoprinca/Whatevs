//
// Created by Todea  Catalin on 26.04.2021.
//

#ifndef TCIE2431_LAB6_CSVFILEMANAGER_H
#define TCIE2431_LAB6_CSVFILEMANAGER_H

#include "FileManager.h"
#include <utility>

using namespace std;

class CSVFileManager: public FileManager {
public:
    CSVFileManager(string fileName): FileManager(move(fileName)) {};
    void writeToFile(vector<TrenchCoat>) override;
    vector<TrenchCoat> readFromFile() override;
    void open() override;
};


#endif //TCIE2431_LAB6_CSVFILEMANAGER_H
