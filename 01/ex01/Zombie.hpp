#ifndef EX00_ZOMBIE_HPP
#define EX00_ZOMBIE_HPP
#include <iostream>

class Zombie
{
private:
    std::string _name;
public:
    Zombie(std::string name);
    Zombie();
    void SetName(std::string name);
    void announce(void);
    ~Zombie();

};


#endif //EX00_ZOMBIE_HPP
