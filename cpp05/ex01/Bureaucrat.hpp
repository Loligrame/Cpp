#pragma once
#include <iostream>
#include <stdexcept>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define BOLD "\033[1m"
#define RESET "\033[0m"


class Form;

class Bureaucrat{
    private :
        std::string const name;
        int grade;
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
        class AlreadySignedException : public std::exception 
        {
            public:
                const char* what() const throw() 
                {return RED "The contract is already signed!" RESET;}
        };
        Bureaucrat &operator=(const Bureaucrat& obj);
        Bureaucrat();
        Bureaucrat(std::string const &name, int grade);
        void increaseGrade();
        void decreaseGrade();
        void signForm(Form &form);
        Bureaucrat(const Bureaucrat& obj);
        const std::string &getName() const;
        const int        &getGrade() const;
        void             setGrade(int grade);
        ~Bureaucrat();
};

std::ostream &operator<<(std::ostream& obj, const Bureaucrat& bur);
#include "Form.hpp"