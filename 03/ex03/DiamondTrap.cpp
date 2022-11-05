#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name): FragTrap(name), ScavTrap(name)
{
    _name = name;
    ClapTrap::_name = name + "_clap_name";
    _hp = FragTrap::_hp;
    _energy = ScavTrap::_energy;
    _damage = FragTrap::_damage;

    std::cout << "DiamondTrap constructor called (" << _name << ")" << std::endl;
    std::cout << "Clap name : " << ClapTrap::_name << std::endl;
    std::cout << "hp : " << _hp << std::endl;
    std::cout << "energy : " << _energy << std::endl;
    std::cout << "damage : " << _damage << std::endl;
}


void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

std::string DiamondTrap::GetName() const
{
    return _name;
}

void DiamondTrap::whoAmI()
{
    std::cout << "- - - - -" << std::endl;
    std::cout << "My name is " << _name << std::endl;
    std::cout << "My clap name is " << ClapTrap::_name << std::endl;
    std::cout << "- - - - -" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called" <<  " (" << _name << ")"
              << std::endl;
}