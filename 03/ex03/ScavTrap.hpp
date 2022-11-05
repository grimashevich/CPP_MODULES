#ifndef EX01_SCAVTRAP_HPP
#define EX01_SCAVTRAP_HPP
#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
public:
    ScavTrap();
    ScavTrap(std::string name);

    void attack(const std::string& target);
    void guardGate();
    ~ScavTrap();
};


#endif //EX01_SCAVTRAP_HPP
