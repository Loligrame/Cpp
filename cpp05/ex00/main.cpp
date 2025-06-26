#include "Bureaucrat.hpp"

int main()
{   
    try{
        Bureaucrat Thierry("Thierry", 1);
        Bureaucrat George("George", 150);
        Bureaucrat Luc("Luc", 15);
        
        std::cout << Thierry << std::endl;
        std::cout << George << std::endl;
        std::cout << Luc << std::endl;

        std::cout << BOLD << "\n--- Test de modification des grades ---\n" << RESET;
        Thierry.increaseGrade();  // Va lancer une exception en interne
        George.decreaseGrade();   // Va lancer une exception en interne
        // Luc.increaseGrade();      // Devrait réussir
        Luc.decreaseGrade();      // Devrait réussir
        std::cout << BOLD << "\n--- Affichage après modification ---\n" << RESET;
        std::cout << Thierry << std::endl;
        std::cout << George << std::endl;
        std::cout << Luc << std::endl;
    }
    catch (std::exception &e){std::cout << e.what() << std::endl;}

    try{
    std::cout << BOLD << "\n--- Test de création invalide ---\n" << RESET;

    Bureaucrat tooHigh("TooHigh", 0);     // Exception interne
    Bureaucrat tooLow("TooLow", 200);     // Exception interne
    }

    catch (std::exception &e){std::cout << e.what() << std::endl;}
    return 0;
}