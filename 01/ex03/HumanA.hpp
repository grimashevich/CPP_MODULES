#ifndef EX03_HUMANA_HPP
#define EX03_HUMANA_HPP
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
private:
    std::string _name;
    Weapon &_weapon;
public:
    HumanA(std::string name, Weapon &weapon);
    void attack();
};


#endif //EX03_HUMANA_HPP
