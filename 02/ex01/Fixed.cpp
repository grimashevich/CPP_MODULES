#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    _value = 0;
}

Fixed::Fixed(const Fixed &source)
{
    std::cout << "Copy constructor called" << std::endl;
    _value = source.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &source)
{
    std::cout << "Copy assignment operator called" << std::endl;
    _value = source.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _value;
}

void Fixed::setRawBits(const int raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    _value = raw;
}

Fixed::Fixed(const int i)
{
    _value = i << _fractionalBits;
}

Fixed::Fixed(const float f)
{
    _value = roundf(f * (1 << _fractionalBits));
}

float Fixed::toFloat(void) const
{
    return (float) _value / (float)(1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
    return _value >> _fractionalBits;
}

std::ostream &operator << (std::ostream &os, const Fixed &fixed)
{
    return os << fixed.toFloat();
}
