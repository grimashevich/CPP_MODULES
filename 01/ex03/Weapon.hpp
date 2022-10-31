#ifndef EX03_WEAPON_HPP
#define EX03_WEAPON_HPP
#include <iostream>

class Weapon
{
private:
    std::string _type;
public:
    Weapon(std::string type);
    const std::string &getType();
    void setType(std::string type);
};


#endif //EX03_WEAPON_HPP
