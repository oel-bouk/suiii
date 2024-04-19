#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include "Form.hpp"
# define MIN_GRADE 150
# define MAX_GRADE 1
class Form;
class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        Bureaucrat(const Bureaucrat &src);
        Bureaucrat &operator=(const Bureaucrat &src);
        void signForm(Form &Form) const;
        //exption classes

        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, Bureaucrat &obj);

#endif