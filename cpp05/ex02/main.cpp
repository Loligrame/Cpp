#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main()
{
        Bureaucrat thierry("Thierry", 1);
        Bureaucrat george("George", 45);
        Bureaucrat luc("Luc", 140);

        ShrubberyCreationForm shrubbery("Garden");
        RobotomyRequestForm robotomy("Marvin");
        PresidentialPardonForm pardon("Arthur");

        std::cout << BOLD << "\n--- Affichage initial ---\n" << RESET;
        std::cout << thierry << std::endl;
        std::cout << george << std::endl;
        std::cout << luc << std::endl;

        std::cout << shrubbery << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << pardon << std::endl;

        std::cout << BOLD << "\n--- Tentatives de signatures ---\n" << RESET;
        luc.signForm(shrubbery);        // devrait fonctionner
        luc.signForm(robotomy);         // devrait échouer
        george.signForm(robotomy);      // devrait fonctionner
        george.signForm(pardon);        // devrait échouer
        thierry.signForm(pardon);       // devrait fonctionner

        try{
            std::cout << BOLD << "\n--- Tentatives d'exécution ---\n" << RESET;
            luc.executeForm(shrubbery);     // devrait échouer (grade trop bas)
            george.executeForm(robotomy);   // devrait fonctionner (avec bruit et succès/échec)
            thierry.executeForm(pardon);    // devrait fonctionner
            george.executeForm(shrubbery);     // devrait échouer (grade trop bas)
            robotomy.execute(george);     // devrait reussir (grade trop bas)
        
            std::cout << BOLD << "\n--- Re-Affichage final ---\n" << RESET;
            std::cout << shrubbery << std::endl;
            std::cout << robotomy << std::endl;
            std::cout << pardon << std::endl;
        }
        catch(const std::exception &e){std::cout << e.what() << std::endl;}
    

    return 0;
}