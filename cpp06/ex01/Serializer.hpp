#pragma once
#include <iostream>
// #include <cstdint>
#include <stdint.h> 

typedef struct Data{
    unsigned int x;
    std::string name;
} Data;

class Serializer{
    private :
        Serializer();
        Serializer(const Serializer &obj);
        Serializer &operator=(const Serializer &obj);
        ~Serializer();
    public:
        uintptr_t serialize(Data* ptr);
        Data* deserialize(uintptr_t raw);
};