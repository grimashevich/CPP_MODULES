#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    static int id = 0;
    std::ostringstream strID;
    strID << id++;
    _name = "ScavTrap" +  strID.str();
    _hp = 100;
    _energy = 50;
    _damage = 20;

    std::cout << "ScavTrap default constructor called" <<
              " (" << _name << ")" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    _name = name;
    std::cout << "ScavTrap constructor called" <<  " (" << _name << ")" << std::endl;
    _hp = 100;
    _energy = 50;
    _damage = 20;
}

void ScavTrap::attack(const std::string &target)
{
    std::cout << "ScavTrap " << GetName() << " is trying to attack " <<
              target << std::endl;
    if (GetEnergy() <= 0)
        return SayTired();
    if (GetHp() <= 0)
        return SayDead();

    std::cout << "ScavTrap " << _name << " attacks " << target;
    std::cout << " causing " << GetDamage()  <<" points of damage!"
              << std::endl;
    _energy--;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap: I'm in gate keeper mode now!" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" <<  " (" << _name << ")" << std::endl;
}

