//
// Created by Todea  Catalin on 04.04.2021.
//

#ifndef TCIE2431_LAB6_DYNAMICVECTOR_H
#define TCIE2431_LAB6_DYNAMICVECTOR_H

#include <stdio.h>

template <typename T>
class DynamicVector {
private:
    T* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;

    void realloc(size_t newCapacity) {
        T* newBlock = new T[newCapacity];

        size_t size = this->size;
        if (newCapacity < size)
            size = newCapacity;

        for (size_t i = 0; i < size; i++)
            newBlock[i] = data[i];

        delete[] data;
        data = newBlock;
        capacity = newCapacity;
    }
public:
    DynamicVector() {
        //start with 2 elements
        realloc(2);
    }

    ~DynamicVector() {
        delete[] data;
    }

    void pushBack(const T& value) {
        if (size >= capacity)
        {
            realloc(capacity + capacity / 2);
        }

        data[size] = value;
        size++;
    }
    void del(size_t index) {
        if (index >= 0 && index <= size)
        {
            for (size_t i = index; i < size - 1; i++)
                data[i] = data[i + 1];
            size--;
        }
    }

    const T& operator[](size_t index) const {

        return data[index];
    }

    T& operator[](size_t index){
        return data[index];
    }

    size_t Size() const { return size; }
};

#endif //TCIE2431_LAB6_DYNAMICVECTOR_H
