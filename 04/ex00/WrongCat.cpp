#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "WrongCat constructor called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat: Ouuuuuu!" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}


