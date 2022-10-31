#include <iostream>
#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main()
{
    Zombie *bob = newZombie("Bob");
    bob->announce();
    delete bob;
    randomChump("Kenny");
    return 0;
}

Zombie *newZombie(std::string name)
{
    return new Zombie(name);
}

void randomChump(std::string name)
{
    Zombie zombie = Zombie(name);
    zombie.announce();
}