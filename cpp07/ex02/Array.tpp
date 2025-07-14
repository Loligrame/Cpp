#include "Array.hpp"

template <typename T>
Array<T>:: Array() : size(0), data(NULL){}

template <typename T>
Array<T>:: Array(unsigned int n): size(n), data(new T[n]()){}

template <typename T>
Array<T>:: Array(const Array& obj){
        this->size = obj.size;
        this->data = new T[size];
        for (size_t i = 0; i < size; i++)
            data[i] = obj.data[i];
}

template <typename T>
Array<T>& Array<T>:: operator=(const Array& obj){
    if(this != &obj)
    {
        delete [] data;
        this->size = obj.size;
        this->data = new T[size];
        for (size_t i = 0; i < size; i++)
            data[i] = obj.data[i];
    }
    return *this;
}

template <typename T>
const T& Array<T>:: operator[](unsigned int index) const {
    if (index >= size)
            throw std::out_of_range("Index out of bounds");
    return data[index];
}

template <typename T>
unsigned int Array<T>:: get_size() const {return this->size;}

template <typename T>
Array<T>:: ~Array (){
    delete[] this->data;
}

template <typename T>
T& Array<T>:: operator[](unsigned int index) {
    if (index >= size)
            throw std::out_of_range("Index out of bounds");
    return data[index];
}