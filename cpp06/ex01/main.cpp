#include "Serializer.hpp"

int main() {
    Data data;
    data.x = 42;
    data.name = "Arshe";
    Data* ptr = &data;

    // Convertir pointeur en entier
    uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);

    // Reconversion entier en pointeur
    Data* ptr2 = reinterpret_cast<Data*>(raw);

    std::cout << "Original pointer: " << ptr << std::endl;
    std::cout << "Raw integer: " << raw << std::endl;
    std::cout << "Deserialized pointer: " << ptr2 << std::endl;
    std::cout << "Value via deserialized pointer: " << ptr2->x << std::endl;
    std::cout << "Value via deserialized pointer: " << ptr2->name << std::endl;

    return 0;
}