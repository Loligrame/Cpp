#include "Intern.hpp"

Intern:: Intern(){}

Intern:: Intern(const Intern &obj){*this = obj;}

Intern& Intern:: operator=(const Intern& obj)
{
    if(this != &obj)
        *this = obj;
    return *this;
}

AForm* Intern:: makeForm(std::string formName, std::string target){
    std::string Names[3] = {"presidential pardon", "robotomy request", "shrubberry creation"};
    for(int i = 0; i < 3; ++i){
        if(Names[i] == formName){
            std::cout << "Intern creates " << formName << std::endl;
            switch (i) {
                case 0:
                    return new PresidentialPardonForm(target);
                case 1:
                    return new RobotomyRequestForm(target);
                case 2:
                    return new ShrubberyCreationForm(target);
            }
        }
    }
    throw UnknownFormName();
}

Intern:: ~Intern(){}
