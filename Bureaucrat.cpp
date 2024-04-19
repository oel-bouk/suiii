#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() :  name(""), grade(MAX_GRADE)
{
    // std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade_src) : name(name)
{
    if(grade_src > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }

    else if(grade_src <= 0)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    grade = grade_src;
}

Bureaucrat::~Bureaucrat()
{
    // std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
    // std::cout << "Bureaucrat copy constructor called" << std::endl;
    this->grade = src.grade;
}

void Bureaucrat::incrementGrade()
{
    if((grade - 1) < 1)//recheck
        throw Bureaucrat::GradeTooHighException();
    else
        grade = grade - 1;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src) {
    if (this != &src)
    {
        grade = src.grade;
    }
    return *this;
}

void Bureaucrat::decrementGrade()
{
    if((grade + 1) > 150) //recheck
        throw Bureaucrat::GradeTooLowException();
    else
        grade = grade + 1;
}

std::string Bureaucrat::getName() const// add const 
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "TooHighException";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "TooLowException";
}

std::ostream& operator<<(std::ostream &out, Bureaucrat &obj)
{
    out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
    return (out);
}