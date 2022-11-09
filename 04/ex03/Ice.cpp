#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
    //std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(const Ice &source): AMateria(source.getType())
{
    //std::cout << "Ice copy constructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &source)
{
    AMateria::operator=(source);
    return *this;
}

AMateria *Ice::clone() const
{
    //std::cout << "Ice clone() called" << std::endl;
    return new Ice();
}

Ice::~Ice()
{
    //std::cout << "Ice destructor called" << std::endl;
}