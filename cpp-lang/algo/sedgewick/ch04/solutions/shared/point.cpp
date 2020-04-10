#include "point.h"

#include <cstdlib>
#include <cmath>

Point::Point()
    : _x(0.0),
      _y(0.0)
{
    _x = 1.0 * rand() / RAND_MAX;
    _y = 1.0 * rand() / RAND_MAX;
}

Point::Point(float x, float y)
    : _x(x),
      _y(y)
{
}

float Point::distance(const Point &other) const
{
    float dx = _x - other._x;
    float dy = _y - other._y;
    return sqrt(dx * dx + dy * dy);
}

float Point::distance(float x, float y) const
{
    return distance(Point(x, y));
}

float Point::distance() const
{
    return distance(Point(0.0, 0.0));
}

void Point::setX(float x)
{
    _x = x;
}

void Point::setY(float y)
{
    _y = y;
}

bool Point::operator==(const Point &other) const
{
    return distance(other) < .001;
}

bool Point::operator!=(const Point &other) const
{
    return !(*this == other);
}

std::ostream &operator<<(std::ostream &os, const Point &p)
{
    return (os << "(" << p.x() << ", " << p.y() << ")");
}
