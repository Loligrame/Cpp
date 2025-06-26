#include "AForm.hpp"

AForm:: AForm(const AForm &obj) : name(obj.name), sign_grade(obj.sign_grade), exec_grade(obj.exec_grade) 
{*this = obj;}

AForm:: AForm():  name("name"), sign_grade(12), exec_grade(5) {
    this->Signed =  false;
    if(sign_grade < 1 || exec_grade < 1)
        throw GradeTooHighException();
    if(sign_grade > 150 || exec_grade > 150)
        throw GradeTooLowException();
}

AForm& AForm:: operator=(const AForm& obj){
    this->Signed =  obj.Signed;
    return *this;
}

AForm:: AForm(std::string const &name, int sign_grade, int exec_grade)
:  name(name), sign_grade(sign_grade), exec_grade(exec_grade)
{
    if(sign_grade < 1 || exec_grade < 1)
        throw GradeTooHighException();
    if(sign_grade > 150 || exec_grade > 150)
        throw GradeTooLowException();
    this->Signed = false;
}

const std::string &AForm:: getName() const{return this->name;}
const int &AForm:: getSignGrade() const{return this->sign_grade;}
const int &AForm:: getExecGrade() const{return this->exec_grade;}
const bool &AForm:: getSigned() const {return this->Signed;}

AForm:: ~AForm(){}

std::ostream& operator<<(std::ostream& obj, const AForm& bur) {
    std::cout << bur.getName() << ", form signed grade is " 
        << bur.getSignGrade() << ", form exec grade is " << bur.getExecGrade()  
        << ", form is signed : " << bur.getSigned();
    return obj;
}

void AForm:: beSigned(Bureaucrat &bureaucrat) {
        if(bureaucrat.getGrade() > this->getSignGrade())
            throw GradeTooLowException();
        if(this->getSigned() == true)
            throw AlreadySignedException();
        else
            this->Signed = true;
}
