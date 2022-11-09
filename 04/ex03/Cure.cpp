#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
    //std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(const Cure &source): AMateria(source)
{
    *this = source;
    //std::cout << "Cure copy constructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &source)
{
    AMateria::operator=(source);
    return *this;
}

AMateria *Cure::clone() const
{
    return new Cure();
}

Cure::~Cure()
{
    //std::cout << "Cure destructor called" << std::endl;
}
