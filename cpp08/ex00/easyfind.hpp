#include <iostream>
#include <vector>

template <typename T>
int easyfind(T &a, int n){
    for(size_t i = 0; a[i]; ++i){
        if(a[i] == n)
            return i;
    }
    return -1;
};