#ifndef ADVANCEDQUICKSORT_H
#define ADVANCEDQUICKSORT_H
#include <iostream>
#include <assert.h>

class AdvancedQuickSort
{
public:
    AdvancedQuickSort() = delete;
    ~AdvancedQuickSort() = delete;

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
    static int getPe(T array[], int lower, int upper){
        assert((upper - lower) >= 2);
        int mid = static_cast<int>((lower + upper)/2);
        if(array[lower] < array[mid]){
            if(array[mid] <= array[upper])
                return mid;
            else if (array[mid] >= array[upper]) {
                return upper;
            }
        }
    }

};

#endif // ADVANCEDQUICKSORT_H
