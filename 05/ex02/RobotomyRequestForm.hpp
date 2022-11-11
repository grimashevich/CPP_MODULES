#ifndef EX02_ROBOTOMYREQUESTFORM_HPP
#define EX02_ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>
#include <ctime>
#include "Form.hpp"

class RobotomyRequestForm: public Form
{
public:
    explicit RobotomyRequestForm(std::string target);
    bool execute(Bureaucrat const & executor) const;
};


#endif //EX02_ROBOTOMYREQUESTFORM_HPP
