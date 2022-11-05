#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ScavTrap batman = ScavTrap("Batman");
    FragTrap superman = FragTrap("Superman");
    ClapTrap enemy = ClapTrap("enemy");

    superman.attack("enemy");
    enemy.takeDamage(30);
    enemy.beRepaired(5);

    batman.attack("enemy");
    enemy.takeDamage(20);

    superman.highFivesGuys();
    batman.guardGate();
}