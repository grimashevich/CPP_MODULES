#include <iostream>
#include <fstream>
#include "Harl.hpp"

int main()
{
    Harl harl;
    harl.complain("debug");
    harl.complain("info");
    harl.complain("warning");
    harl.complain("error");


    harl.complain("21");
    harl.complain("42");
    return 0;
}