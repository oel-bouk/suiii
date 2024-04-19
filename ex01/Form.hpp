#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
    private:
        const std::string name;
        bool is_signed;
        const int grade_required_to_sign;
        const int  grade_requirde_to_excuted;
    public:
        ~Form();
        Form();
        std::string getName() const;
        Form(std::string name_src, int grade_required_sing, int grade_requirde_to_excuted);
        Form(const Form& src);
        Form& operator=(const Form& src);
        void beSigned(Bureaucrat obj);
        bool is_signed_getter();
        int get_required_to_sing();
        int get_required_to_excute();

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

std::ostream &operator<<(std::ostream &out, Form &obj);

#endif