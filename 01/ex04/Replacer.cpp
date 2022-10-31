#include "Replacer.hpp"

std::string Replacer::myReplace(std::string base, std::string what, std::string byWhat)
{
    if (what.empty() || base.empty())
        return base;

    size_t currentPosition = 0;
    size_t sizeOfWhat = what.size();
    std::string res = std::string();
    while (true)
    {
        size_t posFinded = base.find(what, currentPosition);
        std::string currentPeace = base.substr(currentPosition, posFinded - currentPosition);
        res += currentPeace;
        if (posFinded == std::string::npos)
            break;
        res += byWhat;
        currentPosition = posFinded + sizeOfWhat;
    }
    return res;
}
