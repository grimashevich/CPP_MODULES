
#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "Debug message" << std::endl;
}

void Harl::info(void)
{
    std::cout << "Info message" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "Warning message" << std::endl;
}

void Harl::error(void)
{
    std::cout << "Error message" << std::endl;
}

void Harl::complain(std::string level)
{
    (void) level;
    void (Harl::*funcs[])() = {
            &Harl::debug,
            &Harl::info,
            &Harl::warning,
            &Harl::error
    };
    std::string levels[] = {
            "debug",
            "info",
            "warning",
            "error"
    };
    int i = 0;
    while (level != levels[i] && i <= 4)
        i++;
    while (i >= 4)
        return;
    (this->*funcs[i])();
}
