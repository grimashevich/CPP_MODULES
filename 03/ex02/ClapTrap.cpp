#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    static int id = 0;
    std::ostringstream strID;
    strID << id++;
    _name = "ClapTrap" +  strID.str();
    _hp = 10;
    _energy = 10;
    _damage = 0;
    std::cout << "Default constructor called (" << _name << ")" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
{
    _name = name;
    _hp = 10;
    _energy = 10;
    _damage = 1;
    std::cout << "Constructor called (" << _name << ")" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &source)
{
    _name = source.GetName();
    _hp = source.GetHp();
    _energy = source.GetEnergy();
    _damage = source.GetDamage();
}

ClapTrap &ClapTrap::operator=(const ClapTrap &source)
{
    _name = source.GetName();
    _hp = source.GetHp();
    _energy = source.GetEnergy();
    _damage = source.GetDamage();
    return *this;
}

void ClapTrap::attack(const std::string &target)
{
    std::cout << "ClapTrap " << GetName() << " is trying to attack " <<
        target << std::endl;
    if (GetEnergy() <= 0)
        return SayTired();
    if (GetHp() <= 0)
        return SayDead();

    std::cout << "ClapTrap " << _name << " attacks " << target;
    std::cout << " causing " << GetDamage()  <<" points of damage!"
        << std::endl;
    _energy--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    unsigned int delta = amount;
    if (amount >= GetHp())
    {
        delta = GetHp();
        _hp = 0;
    }
    else
        _hp -= amount;
    std::cout << "ClapTrap " << _name << " takes damage and loses "
        << delta << " hp. (current hp: " << GetHp() << ")" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    unsigned int delta = amount;

    std::cout << "ClapTrap " << GetName() << " is trying to repair " <<
        amount << " hp" << std::endl;
    if (GetEnergy() <= 0)
        return SayTired();
    if (GetHp() <= 0)
        return SayDead();

    _energy--;
    if (GetHp() + amount >= 10)
    {
        delta = 10 - GetHp();
        _hp = 10;
    }
    else
        _hp += amount;
    std::cout << "ClapTrap " << _name << " recovered " << delta
        << " hp. (current hp: " << GetHp() << ")" << std::endl;
}

std::string ClapTrap::GetName() const
{
    return _name;
}

unsigned int ClapTrap::GetHp() const
{
    return _hp;
}

unsigned int ClapTrap::GetEnergy() const
{
    return _energy;
}

unsigned int ClapTrap::GetDamage() const
{
    return _damage;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called (" << _name << ")" << std::endl;
}

void ClapTrap::SayDead() const
{
    std::cout << "ClapTrap " << GetName() << " has no more HP"
              << std::endl;
}

void ClapTrap::SayTired() const
{
    std::cout << "ClapTrap " << GetName() << " has no more energy"
              << std::endl;
}

void ClapTrap::SetDamage(unsigned int amount)
{
    std::cout << "Now " << GetName() << " has " << amount <<
        " damage attack " << std::endl;
    _damage = amount;
}
