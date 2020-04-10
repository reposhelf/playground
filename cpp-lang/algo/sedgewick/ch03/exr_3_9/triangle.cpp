#include "triangle.h"

#include <cmath>

Triangle::Triangle()
    : _x(), _y(), _z()
{
}

Triangle::Triangle(const Point &x, const Point &y, const Point &z)
    : _x(x), _y(y), _z(z)
{
}

Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3)
    : _x(Point(x1, y1)), _y(Point(x2, y2)), _z(Point(x3, y3))
{
}

double Triangle::semiperimeter() const
{
    double a = _x.distanceTo(_y);
    double b = _y.distanceTo(_z);
    double c = _z.distanceTo(_x);

    return (a + b + c) / 2.0;
}

double Triangle::area() const
{
    double p = semiperimeter();
    double a = _x.distanceTo(_y);
    double b = _y.distanceTo(_z);
    double c = _z.distanceTo(_x);

    return sqrt(p * (p - a) * (p - b) * (p - c));
}

std::ostream &operator<<(std::ostream &out, const Triangle &t)
{
    out << t._x << ", " << t._y << ", " << t._z;
    return out;
}