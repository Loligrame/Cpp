#pragma once
#include <iostream>
#include <stdexcept>
#include <exception>

#define RED "\033[31m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

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
        Bureaucrat &operator=(const Bureaucrat& obj);
        Bureaucrat();
        Bureaucrat(std::string const &name, int grade);
        void increaseGrade();
        void decreaseGrade();
        bool isGradeValid(int grade);
        Bureaucrat(const Bureaucrat& obj);
        const std::string &getName() const;
        const int        &getGrade() const;
        void             setGrade(int grade);
        ~Bureaucrat();
    };
    
std::ostream &operator<<(std::ostream& obj, const Bureaucrat& bur);