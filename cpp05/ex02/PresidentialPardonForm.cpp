#include "PresidentialPardonForm.hpp"

PresidentialPardonForm:: PresidentialPardonForm(const PresidentialPardonForm &obj)
{*this = obj;}

PresidentialPardonForm:: PresidentialPardonForm(): AForm( "PresidentialPardonForm", 25, 5) 
{}

PresidentialPardonForm& PresidentialPardonForm:: operator=(const PresidentialPardonForm& obj){
    this->target = obj.target;
    return *this;
}

PresidentialPardonForm:: PresidentialPardonForm(std::string const &target) : AForm( "PresidentialPardonForm", 25, 5)
{
    this->target = target;
}

void PresidentialPardonForm:: execute(Bureaucrat const & executor) const{
        if(this->getSigned() == false)
            throw NotSignedException();
        if(this->getExecGrade() < executor.getGrade())
            throw GradeTooLowException();
        else
            std::cout << "Informs that " << target << " has been pardoned by Zaphod Beeblebrox.\n";
}

PresidentialPardonForm:: ~PresidentialPardonForm(){}