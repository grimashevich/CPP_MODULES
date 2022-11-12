#ifndef EX02_PRESIDENTIALPARDONFORM_HPP
#define EX02_PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm: public Form
{
public:
    explicit PresidentialPardonForm(std::string target);
    bool execute(Bureaucrat const & executor) const;
};


#endif //EX02_PRESIDENTIALPARDONFORM_HPP
