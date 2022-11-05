#ifndef EX03_DIAMONDTRAP_HPP
#define EX03_DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public virtual FragTrap, public virtual ScavTrap
{
private:
    std::string _name;

public:
    DiamondTrap(std::string name);
    void attack(const std::string& target);
    void whoAmI();
    std::string GetName() const;
    ~DiamondTrap();
};


#endif //EX03_DIAMONDTRAP_HPP
