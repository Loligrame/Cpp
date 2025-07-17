#include "Span.hpp"

Span:: Span() : N(0) {

}

Span:: Span(unsigned int capacity) : N(capacity){
     arr.reserve(N);
}

Span:: Span(const Span &obj){
    this->N = obj.N;
    this->arr = obj.arr;
}

Span& Span:: operator=(const Span& obj){
    if(this != &obj){
        this->N = obj.N;
        this->arr = obj.arr;
    }
    return *this;
}

Span:: ~Span(){}

void Span:: addNumber(int number){
    if (arr.size() >= this->N)
        throw std::out_of_range("Span is already full");
    arr.push_back(number);
}


unsigned int Span:: shortestSpan() const{
    if(arr.size() < 2)
        throw std::logic_error("Not enough numbers");
    unsigned int min = std::numeric_limits<unsigned int>::max();
    std::vector<unsigned int> sorted = this->arr;
    std::sort(sorted.begin(), sorted.end());
    for(size_t i = 0; i < sorted.size(); ++i){
        unsigned int diff = sorted[i + 1] - sorted[i];
        if(diff < min)
                min = diff;
    }
    return min;
}

unsigned int Span:: longestSpan() const{
    if(arr.size() < 2)
        throw std::logic_error("Not enough numbers");
    std::vector<unsigned int> sorted = this->arr;
    std::sort(sorted.begin(), sorted.end());
    unsigned int result = sorted.back() - sorted.front();

    return result;
}

unsigned int Span::  getN(){return this->N;}