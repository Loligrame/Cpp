#include "Span.hpp"

int main(){
    Span yo(10);
    Span yi(10);
    std::srand(std::time(0));
    try{ 
        for(size_t i = 0; i < yo.getN(); ++i){
            int aleatoire = std::rand() % 9999 + 1;
            yo.addNumber(aleatoire);
        }
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
    try{ 
        for(size_t i = 0; i < 11; ++i){
            int aleatoire = std::rand() % 9999 + 1;
            yi.addNumber(aleatoire);
        }
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
    try{
        std::cout << yo.longestSpan() << std::endl;
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
    try{
        std::cout << yo.shortestSpan() << std::endl;
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }

    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    return 0;
}