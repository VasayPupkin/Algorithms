#include <iostream>

#include "Sort.h"

using namespace std;

int main()
{
    int array[] = {50,20,12,15,32,15};
    size_t size = sizeof(array)/sizeof(int);
    Sort::print(array, size);
    Sort::bubbleSort(array, size);
    Sort::print(array, size);
    cout << "Hello World!" << endl;
    return 0;
}
