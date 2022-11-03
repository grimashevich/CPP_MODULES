#ifndef EX03_POINT_HPP
#define EX03_POINT_HPP

#include <iostream>
#include <string>
#include "Fixed.hpp"

class Point
{
private:
    const Fixed _x;
    const Fixed _y;

public:
    Point();
    Point(const float x, const float y);
    Point(const Point& source);

    const Fixed &getX(void)const;
    const Fixed &getY(void)const;

    Point &operator=(const Point &src);

    ~Point();
};
std::ostream	&operator<<(std::ostream &o, Point const point);

#endif //EX03_POINT_HPP
