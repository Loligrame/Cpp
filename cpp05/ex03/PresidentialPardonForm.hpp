#pragma once
#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm{
    private :
        std::string target;
    public :
        PresidentialPardonForm &operator=(const PresidentialPardonForm& obj);
        PresidentialPardonForm();
        PresidentialPardonForm(std::string const &target);
        PresidentialPardonForm(const PresidentialPardonForm& obj);
        ~PresidentialPardonForm();
        void execute(Bureaucrat const & executor) const;
};