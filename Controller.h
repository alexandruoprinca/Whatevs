//
// Created by Todea  Catalin on 04.04.2021.
//

#ifndef TCIE2431_LAB6_CONTROLLER_H
#define TCIE2431_LAB6_CONTROLLER_H


#include <stdio.h>
#include "Repository.h"

using namespace std;

class Controller {
private:
    Repository &repo;

public:
    Controller(Repository& repo);;

    // Creates an object of type TrenchCoat and check if it is already in our database, if not is sent to the Repository method add, otherwise its quanity is increased
    void addCoat(int size, string colour, string photo, float price, int quantity);

    // Creates an object of type TrenchCoat and pass it to the Repository method update
    void updateCoat(int size, string colour, string photo, float price, int quantity, int index);

    //Creates an object of type TrenchCoat and pass it to the Repository method remove
    void delCoat(int index);
    QString printAll();
    std::vector<TrenchCoat>& getList();

    void openFile();
};


#endif //TCIE2431_LAB6_CONTROLLER_H
