#ifndef TRENCHCOAT_H
#define TRENCHCOAT_H
#include <QString>
#include <QVariant>

//class TrenchCoat{
//public:
//    TrenchCoat() = default;
//    TrenchCoat(int _i):i{_i}{};
//    QString toString() const
//      {
//        return first + second + std::to_string(i).c_str();
//      }
//    QString first{"penis"};
//    QString second{"cock"};
//    int i{0};
//};


//#endif // TRENCHCOAT_H


////
//// Created by Todea  Catalin on 04.04.2021.
////

//#ifndef TCIE2431_LAB6_TRENCHCOAT_H
//#define TCIE2431_LAB6_TRENCHCOAT_H


//#include <stdio.h>
//#include <string>

class TrenchCoat {
private:
    int size{};
    std::string colour{};
    std::string photo{};
    float price{};
    int quantity{};

public:

    TrenchCoat();
    TrenchCoat(int, std::string, std::string, float, int);
    TrenchCoat(const TrenchCoat& elem);

    int getSize() const;
    std::string getColour();
    std::string getPhoto();
    float getPrice();
    int getQuantity();

    void setSize(int);
    void setColour(std::string);
    void setPhoto(std::string);
    void setPrice(float);
    void setQuantity(int);

    bool operator==(const TrenchCoat t);

    QString toString() const;

    //Adds 'toAdd' number of Coats to the self TrenchCoat object
    void addQuantity(int toAdd);
    friend std::ostream& operator<<(std::ostream& os, TrenchCoat& tr);
    std::string toCSV();
    std::string toHTML();
};

Q_DECLARE_METATYPE(TrenchCoat);

#endif //TCIE2431_LAB6_TRENCHCOAT_H
