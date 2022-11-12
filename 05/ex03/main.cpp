#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern intern = Intern();

    Bureaucrat bob = Bureaucrat("Bob", 25);
    Bureaucrat arturchik = Bureaucrat("Arturchik", 5);

    Form *shr = intern.makeForm("shrubbery creation", "bob");
    Form *rbt = intern.makeForm("robotomy request", "Elon");
    Form *ppf = intern.makeForm("presidential pardon", "me");

    Form *err = intern.makeForm("any form", "me");
    if (err == NULL)
        std::cout << "Form err is NULL" << std::endl;

    bob.executeForm(*shr);
    bob.executeForm(*rbt);
    arturchik.executeForm(*ppf);

    delete shr;
    delete rbt;
    delete ppf;
}
