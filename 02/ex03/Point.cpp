#include "Point.hpp"

Point::Point(): _x(0), _y(0)
{

}

Point::Point(const float x, const float y): _x(x), _y(y)
{

}

Point::Point(const Point &source) : _x(source.getX()), _y(source.getY())
{

}

const Fixed &Point::getX(void) const
{
    return _x;
}

const Fixed &Point::getY(void) const
{
    return _y;
}

Point &Point::operator=(const Point &src)
{
    if (this != &src)
    {
        const_cast<Fixed&>(_x) = src.getX();
        const_cast<Fixed&>(_y) = src.getY();
    }
    return *this;
}

Point::~Point()
{

}

std::ostream	&operator<<(std::ostream &os, Point const point)
{
    os << "_x: " << point.getX() << " / _y: " << point.getY() << std::endl;
    return (os);
}