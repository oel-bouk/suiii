#include "Form.hpp"

Form::~Form()
{
    // std::cout << "From Destructor called\n";
}

Form::Form() : name(""), is_signed(false) ,grade_required_to_sign(150), grade_requirde_to_excuted(150) {

}

const char* Form::GradeTooHighException::what() const throw()
{
    return "TooHighException";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "TooLowException";
}

Form& Form::operator=(const Form& src)
{
    // std::cout << "copy assigment called\n";
    if(this != &src)
    {
        this->is_signed = src.is_signed;
    }
    return(*this);
}

Form::Form(const Form& src) : name(src.name), is_signed(src.is_signed)/*check other files*/ ,grade_required_to_sign(src.grade_required_to_sign),grade_requirde_to_excuted(src.grade_requirde_to_excuted)
{
    // std::cout << "copy constructor called\n";
}

Form::Form(std::string name_src, int grade_required_sing, int grade_requirde_excuted) 
    : name(name_src), is_signed(0) /*check other files */,grade_required_to_sign(grade_required_sing) ,grade_requirde_to_excuted(grade_requirde_excuted)
{
    if(grade_required_sing > 150 || grade_requirde_excuted > 150)
    {
        throw Form::GradeTooLowException();
    }
    if(grade_required_sing < 1 || grade_requirde_excuted < 1)
    {
        throw Form::GradeTooHighException();
    }
}

void Form::beSigned(Bureaucrat obj)
{
    if(obj.getGrade() <= grade_required_to_sign)
        is_signed = true;
    else
        throw GradeTooLowException();
}

std::string Form::getName() const
{
    return (name);
}

bool Form::is_signed_getter()
{
     return(is_signed);
}

int Form::get_required_to_excute()
{
    return(grade_requirde_to_excuted);
}

int Form::get_required_to_sing()
{
    return(grade_required_to_sign);
}

std::ostream &operator<<(std::ostream &out, Form &obj)
{
    out << "Form name: " << obj.getName() << " sing: " << obj.is_signed_getter() << " grade required to execute: " << obj.get_required_to_excute() << " grade required to sing: " << obj.get_required_to_sing() << "\n";
    return(out);
}