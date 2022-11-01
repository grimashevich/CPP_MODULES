#include <iostream>
#include "Harl.hpp"

/*
 * WARNING!!!
 * For Mac please remove flag for c++ : -Werror=implicit-fallthrough=0
 * For Ubuntu keep it
 * */

int main(int argc, char **argv)
{
    (void) argc;
    std::string levels[] = {
            "DEBUG",
            "INFO",
            "WARNING",
            "ERROR"
    };
    int i = 0;
    while (argv[1] != levels[i] && i <= 4)
        i++;
    Harl harl;

    switch (i)
    {
        case 0:
            harl.complain("debug");
        case 1:
            harl.complain("info");
        case 2:
            harl.complain("warning");
        case 3:
            harl.complain("error");
            break;
        default:
            std::cerr << "Wrong level argument" << std::endl;
    }
    return 0;
}