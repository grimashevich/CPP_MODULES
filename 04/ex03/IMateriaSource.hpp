#ifndef EX03_IMATERIASOURCE_HPP
#define EX03_IMATERIASOURCE_HPP

#ifndef INVENTORY_CAPACITY
# define INVENTORY_CAPACITY 4
#endif //INVENTORY_CAPACITY

#include "AMateria.hpp"

class IMateriaSource
{
public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif //EX03_IMATERIASOURCE_HPP
