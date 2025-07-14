#include "Iter.hpp"

int main(){
    
    int array[] = {1, 2, 3, 4};

    std::cout << "Tableau original : ";
    printArray(array);

    ::iter(array, sizeof(array)/sizeof(array[0]), doubleunit);
    
    std::cout << "\nTableau après doublement : ";
    printArray(array);
    return 0;
}