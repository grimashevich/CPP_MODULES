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
    //Copy constructor
    Fixed(const Fixed &source);
    Fixed &operator=(const Fixed &source);
    ~Fixed();

    int getRawBits( void ) const;
    void setRawBits( int const raw );
};


#endif //EX00_FIXED_HPP
