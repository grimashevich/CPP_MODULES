#include "Cat.hpp"

Cat::Cat()
{
    type = "cat";
    std::cout << "Cat constructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Cat: Meeeeeooww!" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}


