#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H
#include <iostream>

class SelectionSort
{
public:
    SelectionSort() = delete;
    ~SelectionSort() = delete;

    template<class T>
    static void print(T array[], size_t size){
        for (auto i = 0; i < size; ++i) {
            std::cout<<array[i]<<"\t";
        }
        std::cout<<std::endl;
    }

    template<class T>
    static void swap(T array[], int pos_1, int pos_2){
        T tmp = array[pos_1];
        array[pos_1] = array[pos_2];
        array[pos_2] = tmp;
    }

    template<class T>
    static int getMinIndex(T array[], int left, int right){
        int minIndex = left;
        for(auto i = left; i <= right; ++i){
            if(array[i] < array[minIndex])
                minIndex = i;
        }
        return minIndex;
    }

    template<class T>
    static void selectionSort(T array[], size_t size){
        int minIndex;
        for(auto i = 0; i< size - 1; ++i){
            minIndex = getMinIndex(array, i, size);
            if(minIndex != i)
                swap(array, i, minIndex);
        }
    }
};

#endif // SELECTIONSORT_H
