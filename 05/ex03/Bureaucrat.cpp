#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(): _name("NoName"), _grade(150),
    GradeTooHighException("Error! To high grade for " + _name),
    GradeTooLowException("Error! To low grade for " + _name)
{
    std::cout << "Default Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name),
    GradeTooHighException("Error! To high grade for " + _name),
    GradeTooLowException("Error! To low grade for " + _name)
{
    if (grade < 1)
        throw GradeTooHighException;
    if (grade > 150)
        throw GradeTooLowException;
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &source):
    _name(source._name),
    _grade(source._grade),
    GradeTooHighException("Error! To high grade for " + _name),
    GradeTooLowException("Error! To low grade for " + _name)
{

}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &source)
{
    _grade = source._grade;
    return *this;
}

std::string Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::gradeUp()
{
    if (_grade <= 1)
        throw GradeTooHighException;
    _grade--;
}

void Bureaucrat::gradeDown()
{
    if (_grade >= 150)
        throw GradeTooLowException;
    _grade++;
}

Bureaucrat::~Bureaucrat()
{

}

bool Bureaucrat::signGorm(Form &form)
{
    if (form.getIsSigned())
    {
        std::cout << "Error! Form " << form.getName() <<
            " is already signed" << std::endl;
        return false;
    }
    try { form.BeSigned(*this); }
    catch (std::underflow_error &)
    {
        std::cout << getName() << " couldn’t sign " << form.getName() <<
            " because his grade is too low" << std::endl;
        return false;
    }
    std::cout << getName() << " signed " << form.getName() << std::endl;
    return true;
}

bool Bureaucrat::executeForm(Form &form)
{
    if (form.execute(*this))
    {
        std::cout << _name << " executed " << form.getName() << "." << std::endl;
        return true;
    }
    std::cout << _name << " execution " << form.getName() << " failed "<<
        " because grade to low." << std::endl;
    return false;
}


std::ostream& operator<<(std::ostream &os, const Bureaucrat &b)
{
    return os << b.getName() << " bureaucrat grade " << b.getGrade();
}
