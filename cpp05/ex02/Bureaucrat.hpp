#pragma once
#include <iostream>
#include <stdexcept>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

class AForm;

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
        class NotSignedException : public std::exception 
        {
            public:
                const char* what() const throw() 
                {return RED "The contract is not signed!" RESET;}
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
        void signForm(AForm &form);
        Bureaucrat(const Bureaucrat& obj);
        void executeForm(AForm const & form) const;
        const std::string &getName() const;
        const int        &getGrade() const;
        void             setGrade(int grade);
        ~Bureaucrat();
};

std::ostream &operator<<(std::ostream& obj, const Bureaucrat& bur);
#include "AForm.hpp"