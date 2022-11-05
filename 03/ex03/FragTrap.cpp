#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    static int id = 0;
    std::ostringstream strID;
    strID << id++;
    _name = "FragTrap" +  strID.str();
    _hp = 100;
    _energy = 100;
    _damage = 30;
    std::cout << "FragTrap default constructor called (" << _name << ")"
        << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    _name = name;
    std::cout << "FragTrap constructor called" <<  " (" << _name << ")"
        << std::endl;
    _hp = 100;
    _energy = 100;
    _damage = 30;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap: High five, guys!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" <<  " (" << _name << ")"
        << std::endl;
}


