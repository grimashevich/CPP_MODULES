#ifndef EX00_CAT_HPP
#define EX00_CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
private:
    Brain *_brain;
public:
    Cat();

    Cat(const Cat& source);
    Cat& operator=(const Cat& source);

    void sayIdea(int index);
    void makeSound() const;
    ~Cat();
};


#endif //EX00_CAT_HPP
