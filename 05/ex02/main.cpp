#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat bob = Bureaucrat("Bob", 25);
    Bureaucrat arturchik = Bureaucrat("Arturchik", 5);

    ShrubberyCreationForm shr = ShrubberyCreationForm("Bob");
    RobotomyRequestForm rbt = RobotomyRequestForm("Elon Mask");
    PresidentialPardonForm ppf = PresidentialPardonForm("School adm");

    bob.executeForm(shr);
    bob.executeForm(rbt);
    bob.executeForm(ppf);

    arturchik.executeForm(ppf);

}
