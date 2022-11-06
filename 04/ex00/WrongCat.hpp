#ifndef EX00_WRONG_CAT_HPP
#define EX00_WrongCat_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
public:
    WrongCat();
    void makeSound() const;
    ~WrongCat();
};


#endif //EX00_WRONG_CAT_HPP
