#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>
#include <ctime>
#include <limits>

class Span{
    private :
        unsigned int N;
        std::vector<unsigned int> arr;
    public :
        Span();
        Span(const Span& obj);
        Span(unsigned int capacity);
        Span& operator=(const Span& obj);
        ~Span();

        void addNumber(int number);
        unsigned int getN();
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;
};