#ifndef SORT_H
#define SORT_H
#include <iostream>


class Sort
{
public:
    Sort() = delete;
    ~Sort() = delete;

    template<class T>
    static void swap(T array[], int pos_1, int pos_2){
        T tmp = array[pos_1];
        array[pos_1] = array[pos_2];
        array[pos_2] = tmp;
    }

    template<class T>
    static void print(T array[], size_t size){
        for (auto i = 0; i < size; ++i) {
            std::cout<<array[i]<<"\t";
        }
        std::cout<<std::endl;
    }

    template<class T>
    static void bubbleSort(T array[], size_t size){
        for(auto i = 0; i < size; ++i){
            for(auto j = size - 1; j > i; --j){
                if(array[j-1] > array[j])
                    swap(array, j-1, j);
            }
        }
    }
};

#endif // SORT_H
