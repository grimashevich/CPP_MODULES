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

bool Fixed::operator<(Fixed fixed) const
{
    return toFloat() < fixed.toFloat();
}

bool Fixed::operator>(Fixed fixed) const
{
    return toFloat() > fixed.toFloat();
}

bool Fixed::operator>=(Fixed fixed) const
{
    return toFloat() >= fixed.toFloat();
}

bool Fixed::operator<=(Fixed fixed) const
{
    return toFloat() <= fixed.toFloat();
}

bool Fixed::operator==(Fixed fixed) const
{
    return toFloat() == fixed.toFloat();
}

bool Fixed::operator!=(Fixed fixed) const
{
    return toFloat() != fixed.toFloat();
}

float Fixed::operator+(Fixed fixed) const
{
    return toFloat() + fixed.toFloat();
}

float Fixed::operator-(Fixed fixed) const
{
    return toFloat() - fixed.toFloat();
}

float Fixed::operator*(Fixed fixed) const
{
    return toFloat() * fixed.toFloat();
}

float Fixed::operator/(Fixed fixed) const
{
    return toFloat() / fixed.toFloat();
}

Fixed &Fixed::operator++()
{
    _value++;
    return *this;
}

Fixed &Fixed::operator--()
{
    _value--;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed prev = *this;
    _value++;
    return prev;
}

Fixed Fixed::operator--(int)
{
    Fixed prev = *this;
    _value--;
    return prev;
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
    if (f1.toFloat() <= f2.toFloat())
        return f1;
    return f2;
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
    if (f1.toFloat() <= f2.toFloat())
        return f1;
    return f2;
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
    if (f1.toFloat() >= f2.toFloat())
        return f1;
    return f2;
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
    if (f1.toFloat() >= f2.toFloat())
        return f1;
    return f2;
}


std::ostream &operator << (std::ostream &os, const Fixed &fixed)
{
    return os << fixed.toFloat();
}
