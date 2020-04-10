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

bool Point::isSameLine(double x1, double y1, double x2, double y2) const
{
    // formula: (x1 - x3)(y2 - y3) - (x2 - x3)(y1 - y3) = 0
    if ((((x1 - _x) * (y2 - _y) - (x2 - _x) * (y1 - _y)) <= 0.0001)
        && ((((x1 - _x) * (y2 - _y) - (x2 - _x) * (y1 - _y))) >= -0.0001)) {
        return true;
    }
    return false;
}

bool Point::isSameLine(const Point &p1, const Point &p2) const
{
    return isSameLine(p1.x(), p1.y(), p2.x(), p2.y());
}