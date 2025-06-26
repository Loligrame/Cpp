#include "RobotomyRequestForm.hpp"

RobotomyRequestForm:: RobotomyRequestForm(const RobotomyRequestForm &obj)
{*this = obj;}

RobotomyRequestForm:: RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45) 
{}

RobotomyRequestForm& RobotomyRequestForm:: operator=(const RobotomyRequestForm& obj){
    this->target = obj.target;
    return *this;
}

RobotomyRequestForm:: RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45) 
{
    this->target = target;
}

void RobotomyRequestForm:: execute(Bureaucrat const & executor) const{
        if(this->getSigned() == false)
            throw NotSignedException();
        if(this->getExecGrade() < executor.getGrade())
            throw GradeTooLowException();
        else{
            std::srand(std::time(0));
            int result = std::rand() % 2;
            if(result == 0)
                std::cout << "Drilling Noises, " << target << " has been robotomized\n";
            else
                std::cout << "Drilling Noises, " << target << " robotomization has failed\n";
        }
}

RobotomyRequestForm:: ~RobotomyRequestForm(){}
