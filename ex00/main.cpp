#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"
int main(void)
{ 
    try {
        Bureaucrat bureaucrat("test", 0);
        std::cout << bureaucrat << "\n";
        bureaucrat.decrementGrade();
        std::cout << bureaucrat.getGrade() << "\n";
    }

    catch(std::exception &e){
       try{
        std::cout << e.what() << "\n";
        Bureaucrat bureaucrat("test2", 1);
        std::cout << bureaucrat << "\n";
        bureaucrat.decrementGrade();
        std::cout << bureaucrat.getGrade() << "\n";
       }
        catch(std::exception &ok){
        std::cout << ok.what() << "\n";
    }
    }
    return (0);
}