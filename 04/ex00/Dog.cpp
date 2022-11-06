#include "Dog.hpp"

Dog::Dog()
{
    type = "dog";
    std::cout << "Dog constructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Dog: Woof - woof!" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}


