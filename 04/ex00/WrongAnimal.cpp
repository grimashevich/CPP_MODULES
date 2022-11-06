#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    type = "WrongAnimal";
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &source)
{
    *this = source;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &source)
{
    type = source.type;
    return *this;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal: Hello, sir" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return type;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}


