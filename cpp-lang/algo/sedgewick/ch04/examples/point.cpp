#include "point.h"

#include <cmath>
#include <cstdlib>

Point::Point()
    : _x(0.0),
      _y(0.0)
{
    _x = 1.0 * rand() / RAND_MAX;
    _y = 1.0 * rand() / RAND_MAX;
}

float Point::distance(const Point &other) const
{
    float dx = _x - other._x;
    float dy = _y - other._y;
    return sqrt(dx * dx + dy * dy);
}
