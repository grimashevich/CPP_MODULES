#ifndef EX01_FORM_HPP
#define EX01_FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
private:
    const std::string _name;
    bool _isSigned;
    bool _isExecuted;
    const int _signGrade;
    const int _execGrade;
    const std::string _target;
    std::overflow_error GradeTooHighException;
    std::underflow_error GradeTooLowException;
public:
    Form();
    Form(std::string name, int signGrade, int execGrade, std::string target);

    Form(const Form &source);
    Form& operator=(const Form &source);

    std::string getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;
    std::string getTarget() const;

    void BeSigned(Bureaucrat &b);
    virtual bool execute(Bureaucrat const & executor) const = 0;

    ~Form();
};

std::ostream& operator<<(std::ostream &os, const Form &form);

#endif //EX01_FORM_HPP
