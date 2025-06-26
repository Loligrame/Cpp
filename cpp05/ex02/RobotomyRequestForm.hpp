#pragma once
#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm{
    private :
        std::string target;
    public :
        RobotomyRequestForm &operator=(const RobotomyRequestForm& obj);
        RobotomyRequestForm();
        RobotomyRequestForm(std::string const &target);
        RobotomyRequestForm(const RobotomyRequestForm& obj);
        ~RobotomyRequestForm();
        void execute(Bureaucrat const & executor) const;
};