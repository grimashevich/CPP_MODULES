#ifndef EX00_ANIMAL_HPP
#define EX00_ANIMAL_HPP

#include <iostream>

class WrongAnimal
{
public:
    WrongAnimal();

    WrongAnimal(const WrongAnimal& source);
    WrongAnimal& operator=(const WrongAnimal& source);

    std::string getType() const;
    void makeSound() const;

    ~WrongAnimal();
protected:
    std::string type;
};


#endif //EX00_ANIMAL_HPP
