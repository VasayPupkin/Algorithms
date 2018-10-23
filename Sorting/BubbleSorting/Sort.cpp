#include "Sort.h"

template<class T>
void Sort::swap(T array[], int pos_1, int pos_2)
{
    T tmp = array[pos_1];
    array[pos_1] = array[pos_2];
    array[pos_2] = tmp;
}

template<class T>
void Sort::print(T array[], size_t size)
{
    for (auto i = 0; i < size; ++i) {
        std::cout<<array[i]<<"\t";
    }
    std::cout<<std::endl;
}
