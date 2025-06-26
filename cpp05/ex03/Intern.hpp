#pragma once
#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <map>

class AForm;

class Intern{
    public :
        class UnknownFormName : public std::exception {
            public:
            const char* what() const throw()
            {return RED "The form name is unknown" RESET;}
        };  
        Intern &operator=(const Intern& obj);
        Intern();
        Intern(const Intern& obj);
        AForm* makeForm(std::string formName, std::string target);
        ~Intern();
};

#include "AForm.hpp"