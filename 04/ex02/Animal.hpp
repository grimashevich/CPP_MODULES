#ifndef EX00_WRONG_ANIMAL_HPP
#define EX00_WRONG_ANIMAL_HPP

#include <iostream>

class Animal
{
public:
    Animal();

    Animal(const Animal& source);
    Animal& operator=(const Animal& source);

    std::string getType() const;
    virtual void makeSound() const = 0;

    virtual ~Animal();
protected:
    std::string type;
};


#endif //EX00_WRONG_ANIMAL_HPP
