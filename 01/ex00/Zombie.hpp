#ifndef EX00_ZOMBIE_HPP
#define EX00_ZOMBIE_HPP
#include <iostream>

class Zombie
{
private:
    std::string _name;
public:
    Zombie(std::string name);
    ~Zombie();
    void announce(void);
};


#endif //EX00_ZOMBIE_HPP
