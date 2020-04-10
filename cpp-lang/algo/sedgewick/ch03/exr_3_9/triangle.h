#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "point.h"

#include <ostream>

class Triangle
{
    friend std::ostream &operator<<(std::ostream &out, const Triangle &t);

public:
    explicit Triangle();
    explicit Triangle(const Point &x, const Point &y, const Point &z);
    explicit Triangle(double x1, double y1, double x2, double y2, double x3, double y3);

    double semiperimeter() const;
    double area() const;

private:
    Point _x;
    Point _y;
    Point _z;
};

#endif