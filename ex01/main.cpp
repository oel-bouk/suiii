#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"
int main(void)
{
    try {
        Form f1("test1", 37, 97);
        Form f2("test1", 37, 97);
        Bureaucrat bureaucrat("CR71", 2);
        Bureaucrat bureaucrat2("CR72", 8);
        f1.beSigned(bureaucrat);
        bureaucrat2.signForm(f2);
        std::cout << f1 << "\n";
        std::cout << bureaucrat << std::endl;
        bureaucrat.incrementGrade();
        std::cout << bureaucrat.getGrade() << "\n";
    }

    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try{
        Form xc("ok", 4, 9);
        Bureaucrat obj("test2", 4);
        std::cout << xc << "\n";
        xc.beSigned(obj);
        std::cout << xc << "\n";
    }

    catch(std::exception &bd){
        std::cout  << bd.what() << "\n";
    
    try{
        Form last("last", 50, 9);
        Bureaucrat test2("last3", 9);
        test2.signForm(last);
        std::cout << "---> " << test2 << "\n";
        std::cout << "---> " << last << "\n";
    }
    catch(std::exception test2){
        std::cout << test2.what();
    }   
    return (0);
}

