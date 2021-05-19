//
// Created by Todea  Catalin on 04.04.2021.
//

#ifndef TCIE2431_LAB6_CLIENTCONTROLLER_H
#define TCIE2431_LAB6_CLIENTCONTROLLER_H


#include <stdio.h>
#include "Repository.h"

using namespace std;

class ClientController {
private:
    Repository &repo;
    Repository &basket;
    vector<TrenchCoat> vector;
    int currentCoat = 0;
public:
    ClientController(Repository &repo, Repository &bucket, int size);

    //Returns a string that contains the informations of the current trench coat and the instructions for application
    QString currentCoatToString(int i);
    //Increase the index of the current trench coat
    void nextCoat();
    //Remove the trench coat from the admin repository and add it to the shopping busket
    void buyCoat();
    //Returns a string that contains all the trench coat from the buscket repository and a total amount of money
    QString showBasket();
};

#endif //TCIE2431_LAB6_CLIENTCONTROLLER_H
