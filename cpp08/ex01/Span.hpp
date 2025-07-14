
#include <iostream>

class Span{
    private :
        unsigned int N;
    public :
        Span();
        Span(Span& obj);
        Span& operator=(Span& obj);
        ~Span();

        void addNumber();
        unsigned int getN();
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;
}