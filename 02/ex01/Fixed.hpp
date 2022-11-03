#ifndef EX00_FIXED_HPP
#define EX00_FIXED_HPP
#include <iostream>

class Fixed
{
private:
    int	_value;
    static const int _fractionalBits = 8;
public:
    Fixed();
    Fixed(const int i);
    Fixed(const float f);
    //Copy constructor
    Fixed(const Fixed &source);
    Fixed &operator=(const Fixed &source);
    ~Fixed();

    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;
};
std::ostream &operator << (std::ostream &os, const Fixed &fixed);


#endif //EX00_FIXED_HPP
