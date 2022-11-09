#ifndef EX03_AMATERIA_HPP
#define EX03_AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
protected:
    std::string _type;
    AMateria();
public:
    AMateria(std::string const & type);

    AMateria(const AMateria &source);
    AMateria& operator=(const AMateria &source);

    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);

    virtual ~AMateria();

    void setType(const std::string& newType);
};

#endif //EX03_AMATERIA_HPP
