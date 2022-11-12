#ifndef EX03_INTERN_HPP
#define EX03_INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:
    std::string formNames[3];
public:
    Intern();

    Intern(const Intern &source);
    Intern& operator=(const Intern &source);

    Form *makeForm(std::string name, std::string target);

    ~Intern();
};


#endif //EX03_INTERN_HPP
