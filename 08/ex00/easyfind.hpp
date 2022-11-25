#ifndef EX00_EASYFIND_HPP
#define EX00_EASYFIND_HPP

#include <algorithm>

template<typename T>
typename T::iterator easyFind(T &hayStack, int needle)
{
    return std::find(hayStack.begin(), hayStack.end(), needle);
}

#endif //EX00_EASYFIND_HPP
