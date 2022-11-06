#ifndef EX00_DOG_HPP
#define EX00_DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
private:
    Brain *_brain;
public:
    Dog();

    Dog(const Dog& source);
    Dog& operator=(const Dog& source);

    void sayIdea(int index);
    void makeSound() const;
    ~Dog();
};


#endif //EX00_DOG_HPP
