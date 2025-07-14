
#include <iostream>
#include <stdlib.h>

template <typename T, typename F>
void iter(T *array, int size, F f){
    for(int i = 0 ; i < size ; i++)
        f(array[i]);
};

void doubleunit(int &a){
    a *= 2;
}

template <typename T, int N>
void printArray(T (&array)[N]){
    for(int i = 0 ; i < N ; i++)
        std::cout << array[i] << ", ";
}