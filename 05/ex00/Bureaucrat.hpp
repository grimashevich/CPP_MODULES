#ifndef EX00_BUREAUCRAT_HPP
#define EX00_BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;
    std::overflow_error GradeTooHighException;
    std::underflow_error GradeTooLowException;
public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);

    Bureaucrat(const Bureaucrat &source);
    Bureaucrat& operator=(const Bureaucrat &source);

    std::string getName() const;
    int getGrade() const;
    void gradeUp();
    void gradeDown();


    ~Bureaucrat();
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &b);

#endif
