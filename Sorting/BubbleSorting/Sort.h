#ifndef SORT_H
#define SORT_H
#include <iostream>


class Sort
{
public:
    Sort() = delete;
    ~Sort() = delete;

    template<class T>
    static void swap(T array[], int pos_1, int pos_2);

    template<class T>
    static void print(T array[], size_t size);

    template
};

#endif // SORT_H
