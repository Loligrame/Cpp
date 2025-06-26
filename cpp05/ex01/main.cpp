#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat Thierry("Thierry", 1);
    Bureaucrat George("George", 150);
    Bureaucrat Luc("Luc", 15);

    std::cout << BOLD << "\n--- Petites actions sur les grades ---\n" << RESET;
    try{
        // Thierry.increaseGrade();  // échoue (grade déjà au max)
        // George.decreaseGrade();   // échoue (grade déjà au minimum)
        Luc.increaseGrade();      // passe de 15 à 14
    }
    catch(const std::exception &e){std::cout << e.what() << std::endl;}

    std::cout << BOLD << GREEN  <<  "\nCréation du formulaire Joe !\n" << RESET;
    try{
        Form F("Formulaire Joe", 3, 3);  // nécessite un grade 3 pour signer
        // Form F("Formulaire Joe", 151, 3);  // nécessite un grade 3 pour signer
        // Form F("Formulaire Joe", 3, -1);  // nécessite un grade 3 pour signer
        std::cout << F << std::endl;
    }
    catch(const std::exception &e){std::cout << e.what() << std::endl;}

    std::cout << BOLD << "\n--- Tentative de signature du formulaire ---\n" << RESET;
    try{
        Form F("Formulaire Joe", 3, 2);  // nécessite un grade 3 pour signer
        std::cout << F << std::endl;
        George.signForm(F);   // Échoue
        Luc.signForm(F);      // Échoue
        Thierry.signForm(F);  // Réussit
        Thierry.signForm(F);  // Échoue
        std::cout << F << std::endl;
    }
    catch(const std::exception &e){std::cout << e.what() << std::endl;}

    std::cout << BOLD << "\n--- État final des bureaucrates et du formulaire ---\n" << RESET;
    std::cout << Thierry << std::endl;
    std::cout << George << std::endl;
    std::cout << Luc << std::endl;

    return 0;
}