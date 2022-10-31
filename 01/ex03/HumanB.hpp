#ifndef EX03_HUMANB_HPP
#define EX03_HUMANB_HPP
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
private:
    std::string _name;
    Weapon *_weapon;
public:
    HumanB(std::string name);
    void attack();
    void setWeapon(Weapon &weapon);
};


#endif //EX03_HUMANB_HPP
