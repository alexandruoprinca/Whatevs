//
// Created by Todea  Catalin on 04.04.2021.
//

#ifndef TCIE2431_LAB6_READER_H
#define TCIE2431_LAB6_READER_H

#include <stdio.h>
#include <iostream>
#include <exception>

using namespace std;

class InputException: public exception {
    const char* what() const noexcept override {
        return "Invalid input, try again > ";
    }
};

class Reader {
public:

    static int getInt() {
        string a;
        int nr;

        cin >> a;

        try {
            return stoi(a);
        } catch(...) {
            throw InputException();
        }
    }

    static int readInt() {
        int nr;

        try {
            nr = getInt();
        } catch(exception &ex) {
            cout << ex.what();
            readInt();
        }
        return nr;
    }

    static float getFloat() {
        string a;

        cin >> a;

        try {
            return stof(a);
        } catch(...) {
            throw InputException();
        }
    }

    static int readFloat() {
        float nr;

        try {
            nr = getFloat();
        } catch(exception &ex) {
            cout << ex.what();
            return readFloat();
        }

        return nr;
    }

};

#endif //TCIE2431_LAB6_READER_H
