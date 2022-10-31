#include <iostream>
#include <fstream>
#include "Replacer.hpp"

int main(int argc, char **argv)
{
    if (argc < 4)
    {
        std::cerr << "Expected 3 parameters" << std::endl;
        return 1;
    }

    std::ifstream in(argv[1]);
    if (! in.is_open())
    {
        std::cerr << "Error reading from " << argv[1] << " file" << std::endl;
        return 1;
    }

    std::string outFile = (std::string)argv[1] + ".replace";
    std::ofstream out(&(outFile[0]));
    if (! out.is_open())
    {
        std::cerr << "Error writing to " << outFile << " file" << std::endl;
        in.close();
        return 1;
    }

    std::string line;
    while (getline(in, line))
    {
        out << Replacer::myReplace(line, argv[2], argv[3])
            << std::endl;
    }
    in.close();
    out.close();
    return 0;
}