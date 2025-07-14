#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void){
    std::srand(std::time(0));
    int index = std::rand() % 3;

    if(index == 0)
        return new A();
    else if(index == 1)
        return new B();
    else
        return new C();
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "C\n";
    else
        std::cout << "Unknown type\n";
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A\n";
    } 
    catch (std::exception &e) {
        try {
            (void)dynamic_cast<B&>(p);
            std::cout << "B\n";
        } 
        catch (std::exception &e) {
            try {
                (void)dynamic_cast<C&>(p);
                std::cout << "C\n";
            } 
            catch (std::exception &e) {
                std::cout << "Unknown type\n";
            }
        }
    }
}


int main() {
    Base* obj = generate();

    std::cout << "Identification par pointeur : ";
    identify(obj);

    std::cout << "Identification par référence : ";
    identify(*obj);

    delete obj;
    return 0;
}