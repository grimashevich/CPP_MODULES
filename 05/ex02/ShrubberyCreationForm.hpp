#ifndef EX02_SHRUBBERYCREATIONFORM_HPP
#define EX02_SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "Form.hpp"

class ShrubberyCreationForm: public Form
{
public:
    explicit ShrubberyCreationForm(std::string target);
    bool execute(Bureaucrat const & executor) const;
};


#endif //EX02_SHRUBBERYCREATIONFORM_HPP
