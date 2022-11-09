#include "Character.hpp"

Character::Character()
{
    //std::cout << "*** Default character constructor called" <<
    //    std::endl;
    _holder = NULL;
    _name = "Unknown character";
}

Character::Character(std::string name)
{
    //std::cout << "*** Character constructor called" << std::endl;
    _name = name;
    _holder = NULL;;
}

Character::Character(const Character &source)
{
    *this = source;
}

Character &Character::operator=(const Character &source)
{
    _name = source._name;
    this->freeInventory();
    for (int i = 0; i < INVENTORY_CAPACITY; ++i)
    {
        if (source._inventory[i] != NULL)
            _inventory[i] = source._inventory[i]->clone();
    }
    return *this;
}

std::string const &Character::getName() const
{
    return _name;
}

void Character::equip(AMateria *m)
{
    if (! m)
        return;
    int i = 0;
    for (; i < INVENTORY_CAPACITY; ++i)
    {
        if (_inventory[i] == NULL)
            break;
    }
    if (i == INVENTORY_CAPACITY)
        return;
    _inventory[i] = m;
}

void Character::unequip(int idx)
{
    if (idx >= INVENTORY_CAPACITY || _inventory[idx] == NULL)
        return;
    keepInHolder(_inventory[idx]);
    _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= INVENTORY_CAPACITY || _inventory[idx] == NULL)
        return;
    _inventory[idx]->use(target);
    _inventory[idx] = NULL;
}

void Character::keepInHolder(AMateria *m)
{
    sAmateriaHolder *current = _holder;
    if (m == NULL)
        return;
    if (current == NULL)
    {
        _holder = current = new tAmateriaHolder;
    }
    else
    {
        while (current->next != NULL)
            current = current->next;
        current->next = new tAmateriaHolder;
        current = current->next;
    }
    current->m = m;
}

void Character::freeHolder()
{
    sAmateriaHolder *current = _holder;
    sAmateriaHolder *tmp;
    while (current != NULL)
    {
        tmp = current;
        current = current->next;
        delete tmp->m;
        delete tmp;
    }
}

void Character::freeInventory()
{
    for (int i = 0; i < INVENTORY_CAPACITY; ++i)
    {
        if (_inventory[i] != NULL)
        {
            delete _inventory[i];
            _inventory[i] = NULL;
        }
    }
}

Character::~Character()
{
    //std::cout << "*** Character destructor called" << std::endl;
    freeHolder();
    freeInventory();
}

