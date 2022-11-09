#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    //std::cout << "Default MateriaSource constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &source)
{
    *this = source;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &source)
{
    for (int i = 0; i < INVENTORY_CAPACITY; ++i)
    {
        if (source._wareHouse[i] != NULL)
            _wareHouse[i] = source._wareHouse[i]->clone();
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
    int i = 0;
    for (; i < INVENTORY_CAPACITY; ++i)
    {
        if (_wareHouse[i] == NULL)
            break;
    }
    if (i == INVENTORY_CAPACITY)
    {
        std::cout << "No more free space avaliable in the MateriaSource" <<
            std::endl;
        return;
    }
    _wareHouse[i] = m;
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
    int i = 0;
    for (; i < INVENTORY_CAPACITY; ++i)
    {
        if (_wareHouse[i]->getType() == type)
            break;
    }
    if (i >= INVENTORY_CAPACITY)
    {
        std::cout << "Type " << type << " not found in aMateriaSource" <<
                  std::endl;
        return NULL;
    }
    return _wareHouse[i]->clone();
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < INVENTORY_CAPACITY; ++i)
    {
        if (_wareHouse[i] != NULL)
            delete _wareHouse[i];
    }
}
