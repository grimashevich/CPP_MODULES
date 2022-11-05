#ifndef EX02_FRAGTRAP_HPP
#define EX02_FRAGTRAP_HPP
#include <iostream>
#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
public:
    FragTrap();
    FragTrap(std::string name);

    void highFivesGuys();

    ~FragTrap();
};


#endif //EX02_FRAGTRAP_HPP
