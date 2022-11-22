#include <iostream>
#include "Converter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Argument expected" << std::endl;
        return 1;
    }

    Converter c = Converter(argv[1]);
    c.Convert();
    std::cout << c << std::endl;
    return 0;
}