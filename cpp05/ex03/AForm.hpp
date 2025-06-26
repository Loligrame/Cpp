#pragma once
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

class Bureaucrat;

class AForm{
    private :
        std::string const name;
        bool Signed;
        const int sign_grade;
        const int exec_grade;
    public :
        class GradeTooHighException : public std::exception {
                public:
                const char* what() const throw() 
                {return RED "Grade is too high!" RESET;}
            };
        class GradeTooLowException : public std::exception {
                public:
                    const char* what() const throw() 
                    {return RED "Grade is too low!" RESET;}
            };
        class AlreadySignedException : public std::exception {
                public:
                    const char* what() const throw() 
                    {return RED "The contract is already signed!" RESET;}
            };
        class NotSignedException : public std::exception {
                public:
                    const char* what() const throw() 
                    {return RED "The contract is not signed!" RESET;}
            };
        class FileNotCreatedException : public std::exception {
                public:
                    const char* what() const throw() 
                    {return RED "The file was not created !" RESET;}
            };
        AForm &operator=(const AForm& obj);
        AForm();
        AForm(std::string const &name, int sign_grade, int exec_grade);
        void increaseGrade();
        void decreaseGrade();
        void beSigned(Bureaucrat &obj);
        AForm(const AForm& obj);
        const std::string &getName() const;
        virtual void execute(Bureaucrat const & executor) const = 0;
        const int        &getSignGrade() const;
        const int        &getExecGrade() const;
        const bool       &getSigned() const;
        virtual ~AForm();
};

std::ostream& operator<<(std::ostream& obj, const AForm& bur);

#include "Bureaucrat.hpp"