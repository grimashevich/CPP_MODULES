#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target):
        Form("PresidentialPardonForm",
             25,
             5,
             target)
{

}

bool PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    if (executor.getGrade() > Form::getExecGrade())
        return false;
    std::cout << Form::getTarget() << " has been pardoned by Zaphod Beeblebrox" <<
        std::endl;
    return true;
}
