#include "Intern.hpp"

Intern::Intern()
{
    formNames[0] = "shrubbery creation";
    formNames[1] = "robotomy request";
    formNames[2] = "presidential pardon";
}

Intern::Intern(const Intern &source)
{
    *this = source;
}

Intern &Intern::operator=(const Intern &source)
{
    for (int i = 0; i < 3; ++i)
        this->formNames[i] = source.formNames[i];
    return *this;
}

Form *Intern::makeForm(std::string name, std::string target)
{
    int i = 0;
    while (i < 4 && formNames[i] != name)
        i++;
    switch (i)
    {
        case 0:
            std::cout << "Intern creates " << name << " form" << std::endl;
            return new ShrubberyCreationForm(target);
        case 1:
            std::cout << "Intern creates " << name << " form" << std::endl;
            return new RobotomyRequestForm(target);
        case 2:
            std::cout << "Intern creates " << name << " form" << std::endl;
            return new PresidentialPardonForm(target);
        default:
            std::cout << "Intern: given form name is not correct, sorry" << std::endl;
            return NULL;
    }
}

Intern::~Intern()
{

}
