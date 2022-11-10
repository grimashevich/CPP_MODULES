#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat bob = Bureaucrat("Bob", 150);
    std::cout << bob << std::endl;
    try
    {
        bob.gradeDown();
    }
    catch (std::exception &e)
    {
        std::cout << "*** Some exception was throw: " <<
            e.what() << std::endl;
    }

    std::cout << bob << std::endl;

    for (int i = 0; i < 150; ++i)
    {
        try
        {
            bob.gradeUp();
        }
        catch (std::exception &e)
        {
            std::cout << "*** Some exception was throw: " <<
                      e.what() << std::endl;
        }
    }
    std::cout << bob << std::endl;
    return 0;
}