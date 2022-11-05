#ifndef EX00_CLAPTRAP_HPP
#define EX00_CLAPTRAP_HPP

#include <iostream>
#include <string>
#include <sstream>


class ClapTrap
{
protected:
    std::string _name;
    unsigned int _hp;
    unsigned int _energy;
    unsigned int _damage;

    void SayDead() const;
    void SayTired() const;
public:
    ClapTrap();
    ClapTrap(const std::string& name);

    ClapTrap(const ClapTrap& source);
    ClapTrap& operator=(const ClapTrap& source);

    virtual void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    virtual std::string GetName() const;
    unsigned int GetHp() const;
    unsigned int GetEnergy() const;
    unsigned int GetDamage() const;

    void SetDamage(unsigned int amount);

    ~ClapTrap();

};


#endif //EX00_CLAPTRAP_HPP
