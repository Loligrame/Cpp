#include "Span.hpp"

int main(){
    Span good(10);
    Span overflow(10);
    std::srand(std::time(0));
    try{ 
        for(size_t i = 0; i < good.getN(); ++i){
            int aleatoire = std::rand() % 9999 + 1;
            good.addNumber(aleatoire);
        }
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }

    //On essaie de remplir au dela de la size.
    try{ 
        for(size_t i = 0; i < 11; ++i){
            int aleatoire = std::rand() % 9999 + 1;
            overflow.addNumber(aleatoire);
        }
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
    try{
        std::cout << good.longestSpan() << std::endl;
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
    try{
        std::cout << good.shortestSpan() << std::endl;
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