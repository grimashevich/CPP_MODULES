#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ScavTrap batman = ScavTrap("Batman");
    ClapTrap enemy = ClapTrap("enemy");

    batman.attack("enemy");
    enemy.takeDamage(20);
    enemy.beRepaired(5);

    batman.attack("enemy");
    enemy.takeDamage(20);

    batman.guardGate();
}