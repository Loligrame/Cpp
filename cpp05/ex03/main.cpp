#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
    Bureaucrat thierry("Thierry", 1);

    std::cout << BOLD << "\n --- Test Intern --- \n" << RESET;
    Intern someRandomIntern;
    
    AForm* robotomy = someRandomIntern.makeForm("robotomy request", "Bender");
    if (robotomy)
    {
        thierry.signForm(*robotomy);
        thierry.executeForm(*robotomy);
        delete robotomy;
    }
    AForm* shrubberry = someRandomIntern.makeForm("shrubberry creation", "Bender");
    if (shrubberry)
    {
        thierry.signForm(*shrubberry);
        thierry.executeForm(*shrubberry);
        delete shrubberry;
    }
    AForm* presidential = someRandomIntern.makeForm("presidential pardon", "Bender");
    if (presidential)
    {
        thierry.signForm(*presidential);
        thierry.executeForm(*presidential);
        delete presidential;
    }
    try {
        AForm* form2 = someRandomIntern.makeForm("invalid request", "TargetX");
        if (form2) 
            delete form2;
    } 
    catch (const Intern::UnknownFormName &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}