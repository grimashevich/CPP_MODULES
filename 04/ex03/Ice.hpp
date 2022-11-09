#ifndef EX03_ICE_HPP
#define EX03_ICE_HPP

#include "AMateria.hpp"

class Ice: public AMateria
{
public:
    Ice();

    Ice(const Ice &source);
    Ice& operator=(const Ice& source);

    AMateria* clone() const;
    ~Ice();

};


#endif //EX03_ICE_HPP
