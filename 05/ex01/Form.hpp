#ifndef EX01_FORM_HPP
#define EX01_FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
private:
    const std::string _name;
    bool _isSigned;
    const int _signGrade;
    const int _execGrade;
    std::overflow_error GradeTooHighException;
    std::underflow_error GradeTooLowException;
public:
    Form();
    Form(std::string name, int signGrade, int execGrade);

    Form(const Form &source);
    Form& operator=(const Form &source);

    std::string getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;

    void BeSigned(Bureaucrat &b);

    ~Form();
};

std::ostream& operator<<(std::ostream &os, const Form &form);

#endif //EX01_FORM_HPP
