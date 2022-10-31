#include <iostream>
#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );
Zombie* zombieHorde( int N, std::string name );

int main()
{
    int n = 21;
    Zombie *horde = zombieHorde(n, "Steve");
    for (int i = 0; i < n; ++i)
        horde[i].announce();

    delete []horde;

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

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *zombies = new Zombie[N];
    for (int i = 0; i < N; ++i)
        zombies[i].SetName(name);
    return zombies;
}