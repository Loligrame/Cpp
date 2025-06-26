#pragma once
#include <iostream>
#include <stdexcept>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm{
    private :
        std::string target;
    public :
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm& obj);
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string const &target);
        ShrubberyCreationForm(const ShrubberyCreationForm& obj);
        ~ShrubberyCreationForm();
        void execute(Bureaucrat const & executor) const;
};