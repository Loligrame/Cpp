#include "Form.hpp"

Form::Form(const Form &obj) : name(obj.name),
      isSigned(obj.isSigned),
      sign_grade(obj.sign_grade),
      exec_grade(obj.exec_grade) {}

Form:: Form():  name("Contract"), sign_grade(3), exec_grade(3){
    this->isSigned =  false;
    if(sign_grade < 1 || exec_grade < 1)
        throw GradeTooHighException();
    if(sign_grade > 150 || exec_grade > 150)
        throw GradeTooLowException();
}

Form& Form:: operator=(const Form& obj){
    this->isSigned =  obj.isSigned;
    return *this;
}

Form:: Form(std::string const &name, int sign_grade, int exec_grade)
:  name(name), sign_grade(sign_grade), exec_grade(exec_grade)
{
    if(sign_grade < 1 || exec_grade < 1)
        throw GradeTooHighException();
    if(sign_grade > 150 || exec_grade > 150)
        throw GradeTooLowException();
    this->isSigned = false;
}

const std::string &Form:: getName() const{return this->name;}
const int &Form:: getSignGrade() const{return this->sign_grade;}
const int &Form:: getExecGrade() const{return this->exec_grade;}
const bool &Form:: getSigned() const {return this->isSigned;}

Form:: ~Form(){}

std::ostream& operator<<(std::ostream& obj, const Form& bur) {
    obj << bur.getName() << ", form signed grade is " 
    << bur.getSignGrade() << ", form exec grade is " << bur.getExecGrade()  
    << ", form is signed : " << bur.getSigned();
    return obj;
}

void Form:: beSigned(Bureaucrat &bureaucrat) {
        if(bureaucrat.getGrade() > this->getSignGrade())
            throw GradeTooLowException();
        if(this->getSigned() == true)
            throw AlreadySignedException();
        else
            this->isSigned = true;
}