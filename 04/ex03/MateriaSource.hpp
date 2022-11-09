#ifndef EX03_MATERIASOURCE_HPP
#define EX03_MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource: public IMateriaSource
{
private:
    AMateria *_wareHouse[INVENTORY_CAPACITY];
    bool isThereAmateria(AMateria *m);
public:
    MateriaSource();

    MateriaSource(const MateriaSource &source);
    MateriaSource& operator=(const MateriaSource &source);

    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const & type);

    ~MateriaSource();
};


#endif //EX03_MATERIASOURCE_HPP
