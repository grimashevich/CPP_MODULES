#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap dimon = DiamondTrap("Dimon");
    dimon.whoAmI();
    ClapTrap enemy = ClapTrap("enemy");

    dimon.attack("enemy");
    enemy.takeDamage(20);
    enemy.beRepaired(5);
}