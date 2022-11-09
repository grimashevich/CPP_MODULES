#ifndef EX03_CHARACTER_HPP
#define EX03_CHARACTER_HPP

#ifndef INVENTORY_CAPACITY
# define INVENTORY_CAPACITY 4
#endif //INVENTORY_CAPACITY

#include "AMateria.hpp"
#include "ICharacter.hpp"

typedef struct sAmateriaHolder
{
    AMateria *m;
    sAmateriaHolder *next;
} tAmateriaHolder;

class Character: public ICharacter
{
private:
    AMateria *_inventory[INVENTORY_CAPACITY];
    std::string _name;
    tAmateriaHolder *_holder;
    void keepInHolder(AMateria *m);
    void freeHolder();
    void freeInventory();
public:
    Character();
    Character(std::string name);

    Character(const Character &source);
    Character& operator=(const Character &source);

    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);

   ~Character();
};


#endif //EX03_CHARACTER_HPP
