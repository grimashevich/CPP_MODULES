#include "Animal.hpp"

Animal::Animal()
{
    type = "animal";
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &source)
{
    type = source.type;
}

Animal &Animal::operator=(const Animal &source)
{
    type = source.type;
    return *this;
}

void Animal::makeSound() const
{
    std::cout << "Animal: Aaa oo uu  ii fff hh!" << std::endl;
}

std::string Animal::getType() const
{
    return type;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}


