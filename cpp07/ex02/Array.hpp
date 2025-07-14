#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class Array{

    private :
        unsigned int size;
        T* data;
    public :
        Array();
        Array(unsigned int n);
        Array<T>& operator=(const Array &obj);
        Array(const Array &obj);
        ~Array();
        unsigned int get_size() const;\
        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;
};



#include "Array.tpp"
