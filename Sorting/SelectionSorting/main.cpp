#include <iostream>
#include "SelectionSort.h"
using namespace std;

int main()
{
    int array[]{23,12,34,54,34,65,7625,756,0};
    size_t size = sizeof(array)/sizeof(array[0]);
    SelectionSort::print(array,size);
    SelectionSort::selectionSort(array, size);
    SelectionSort::print(array, size);
    cout << "Hello World!" << endl;
    return 0;
}
