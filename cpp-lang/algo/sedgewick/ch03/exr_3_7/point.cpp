#include "point.h"

#include <cmath>

Point::Point()
    : _x(0.0), _y(0.0)
{
}

Point::Point(double x, double y)
    : _x(x), _y(y)
{
}

void Point::setX(double x)
{
    _x = x;
}

void Point::setY(double y)
{
    _y = y;
}

double Point::distanceTo(double x, double y) const
{
    double dx = _x - x;
    double dy = _y - y;

    return sqrt(dx * dx + dy * dy);
}

double Point::distanceTo(const Point &other) const
{
    return distanceTo(other.x(), other.y());
}
