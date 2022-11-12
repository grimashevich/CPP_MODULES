
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target):
        Form("RobotomyRequestForm",
             72,
             45,
             target)
{

}

bool RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (executor.getGrade() > Form::getExecGrade())
        return false;

    std::srand(std::time(NULL));
    if (std::rand() % 2 == 1)
        std::cout << Form::getTarget() << " has been robotomized" << std::endl;
    else
        std::cout << "Robotomy failed" << std::endl;
    return true;
}
