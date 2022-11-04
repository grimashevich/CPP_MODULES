#include <iostream>
#include "ClapTrap.hpp"

int main()
{
    ClapTrap bob = ClapTrap("Bob");
    ClapTrap enemy = ClapTrap("enemy");
    bob.SetDamage(1);
    for (int i = 0; i < 7; ++i)
    {
        bob.attack("enemy");
        enemy.takeDamage(1);
    }
    enemy.beRepaired(12);

    bob.SetDamage(8);
    bob.attack("enemy");
    enemy.takeDamage(8);

    bob.SetDamage(15);
    bob.attack("enemy");
    enemy.takeDamage(15);

    enemy.attack("Bob");
    enemy.takeDamage(15);

    bob.attack("enemy");
    enemy.takeDamage(15);

    bob.attack("enemy");

}