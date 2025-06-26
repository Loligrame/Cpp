#include "Bureaucrat.hpp"

Bureaucrat:: Bureaucrat(const Bureaucrat &obj){*this = obj;}

Bureaucrat& Bureaucrat:: operator=(const Bureaucrat& obj)
{
    this->grade =  obj.grade;
    return *this;
}

Bureaucrat::Bureaucrat() :  name("name"), grade(1){}

Bureaucrat:: Bureaucrat(std::string const &name, int grade) : name(name)
{
    if(grade < 1)
        throw GradeTooHighException();
    if(grade > 150)
        throw GradeTooLowException();
    this->grade =  grade;
}

void Bureaucrat:: increaseGrade()
{

    if(this->grade <= 1)
        throw GradeTooHighException();
    this->grade--;
}

void Bureaucrat:: decreaseGrade()
{

    if(this->grade >= 150)
        throw GradeTooLowException();
    this->grade++;
}

void Bureaucrat:: signForm(Form &form)
{
    try{
        form.beSigned(*this);
        std::cout << GREEN << this->getName() << " signed " << form.getName() 
        << RESET <<std::endl;
    }
    catch(const std::exception &e){
        std::cout << RED << this->getName() << " coudn't sign " 
            << form.getName() << " because " << e.what() << RESET << std::endl;
    }
}

const std::string &Bureaucrat:: getName() const{return this->name;}

const int &Bureaucrat:: getGrade() const{return this->grade;}

Bureaucrat:: ~Bureaucrat(){}

std::ostream& operator<<(std::ostream& obj, const Bureaucrat& bur){
    obj << bur.getName() << ", bureaucrat grade " << bur.getGrade();
    return obj;
}