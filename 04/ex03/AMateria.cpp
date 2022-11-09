#include "AMateria.hpp"

AMateria::AMateria(const std::string &type)
{
    //std::cout << "AMateria constructor called" << std::endl;
    _type = type;
}

AMateria::AMateria()
{
    //std::cout << "Default AMateria constructor called" << std::endl;
    _type = "Unknown";
}

AMateria::AMateria(const AMateria &source)
{
    *this = source;
}

AMateria &AMateria::operator=(const AMateria &source)
{
    _type = source._type;
    return *this;
}

std::string const &AMateria::getType() const
{
    return _type;
}

void AMateria::use(ICharacter &target)
{
    if (_type == "ice")
        std::cout << "* shoots an ice bolt at " <<
            target.getName() << " *" << std::endl;
    else if (_type == "cure")
        std::cout << "* heals " << target.getName() <<
            "’s wounds *" << std::endl;
    else
        std::cout << "Unknown amateria type has been used on " <<
            target.getName() << std::endl;
    delete (this);
}

AMateria::~AMateria()
{
    //std::cout << "AMateria destructor called" << std::endl;
}

void AMateria::setType(const std::string &newType)
{
    _type = newType;
}






