#include "Span.hpp"

Span:: Span() : N(0) {

}

Span:: Span(unsigned int capacity) : N(capacity) {
    std::vector<int, N> arr;
}


Span:: Span(Span& obj){
    this->N = &obj.N;
}

Span& Span:: operator=(Span& obj){
    if(this != &obj)
        this->N = &obj.N;
    return *this;
}

~Span(){}

template <typename T>
void addNumber(){
    std::srand(std::time(nullptr));          // Initialiser le générateur
    int aleatoire = std::rand() % 9999 + 1;    // Nombre entre 1 et 10

    std::cout << "Nombre aléatoire : " << aleatoire << std::endl;
    return 0;
}

unsigned int getN(){ return this->N}

unsigned int shortestSpan() const{

}

unsigned int longestSpan() const{

}