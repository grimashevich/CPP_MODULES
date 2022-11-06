#ifndef EX00_CAT_HPP
#define EX00_CAT_HPP

#include "Animal.hpp"

class Cat: public Animal
{
public:
    Cat();
    void makeSound() const;
    ~Cat();
};


#endif //EX00_CAT_HPP
