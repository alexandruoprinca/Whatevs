//
// Created by Todea  Catalin on 04.04.2021.
//

#ifndef TCIE2431_LAB6_REPOSITORY_H
#define TCIE2431_LAB6_REPOSITORY_H


#include <stdio.h>
#include <vector>
#include <fstream>
#include "TrenchCoat.h"
#include "FileManager.h"

class Repository {
private:
    std::vector<TrenchCoat> container{};
    FileManager &fileManager;
    void writeToFile();
    void readFromFile();

public:

    Repository(FileManager &fileManager): fileManager{fileManager} {};

    //Adds the object 'elem' of type TrenchCoat to the dynamic Vector.
    void addElement(TrenchCoat& elem);

    //Replaces the element from the 'index'th position from the dynamic vector to the element 'elem'
    void update(TrenchCoat elem, int index);

    // Removes the 'index'th object from the dynamic vector
    void del(int index);

    // Returns the 'index'th element from the dynamic vector
    TrenchCoat getCoat(int index);

    // Returns the dynamic vector
    std::vector<TrenchCoat>& getList();

    // Check if 't1' exists in the dynamicVector
    bool checkExistence(TrenchCoat t1);

    void openFile();
};

#endif //TCIE2431_LAB6_REPOSITORY_H
