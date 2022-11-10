#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat bob = Bureaucrat("Bob", 150);
    std::cout << bob << std::endl;
    Form form1 = Form("form1", 148, 150);
    std::cout << form1 << std::endl;
    bob.signGorm(form1);

    bob.gradeUp();
    bob.gradeUp();
    std::cout << bob << std::endl;

    bob.signGorm(form1);
    bob.signGorm(form1);

    std::cout << form1 << std::endl;
}
