#ifndef EX00_DOG_HPP
#define EX00_DOG_HPP

#include "Animal.hpp"

class Dog: public Animal
{
public:
    Dog();
    void makeSound() const;
    ~Dog();
};


#endif //EX00_DOG_HPP
