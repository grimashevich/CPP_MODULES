#ifndef EX03_CURE_HPP
#define EX03_CURE_HPP

#include "AMateria.hpp"

class Cure: public AMateria
{
public:
    Cure();

    Cure(const Cure &source);
    Cure& operator=(const Cure &source);

    AMateria* clone() const;
    ~Cure();
};

#endif //EX03_CURE_HPP
