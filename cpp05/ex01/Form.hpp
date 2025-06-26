#pragma once
#include <iostream>
#include <stdexcept>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

class Bureaucrat;

class Form{
    private :
        std::string const name;
        bool isSigned;
        const int sign_grade;
        const int exec_grade;
    public :
        class GradeTooHighException : public std::exception 
        {
            public:
                const char* what() const throw() 
                {return RED "Grade is too high!" RESET;}
        };
        class GradeTooLowException : public std::exception 
        {
            public:
                const char* what() const throw() 
                {return RED "Grade is too low!" RESET;}
        };
        class AlreadySignedException : public std::exception {
            public:
                const char* what() const throw() 
                {return RED "The contract is already signed!" RESET;}
        };
        Form &operator=(const Form& obj);
        Form();
        Form(std::string const &name, int sign_grade, int exec_grade);
        void increaseGrade();
        void decreaseGrade();
        void beSigned(Bureaucrat &obj);
        Form(const Form& obj);
        const std::string &getName() const;
        const int        &getSignGrade() const;
        const int        &getExecGrade() const;
        const bool        &getSigned() const;
        ~Form();
    };

    std::ostream& operator<<(std::ostream& obj, const Form& bur);

    #include "Bureaucrat.hpp"