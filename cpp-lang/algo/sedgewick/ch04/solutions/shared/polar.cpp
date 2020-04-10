#include "polar.h"
#include "point.h"

#include <cstdlib>
#include <cmath>

Polar::Polar()
    : _radius(0.0),
      _angle(0.0)
{
    _radius = 1.0 * rand() / RAND_MAX;
    _angle = 360.0 * rand() / RAND_MAX;
}

float Polar::distance(const Polar &other) const
{
    float x1 = _radius * cos(_angle * M_PI / 180.0);
    float y1 = _radius * sin(_angle * M_PI / 180.0);
    float x2 = other.radius() * cos(other.angle() * M_PI / 180.0);
    float y2 = other.radius() * sin(other.angle() * M_PI / 180.0);
    const Point p(x1, y1);
    return p.distance(x2, y2);
}

std::ostream &operator<<(std::ostream &os, const Polar &p)
{
    return os << "(" << p.radius() << ", " << p.angle() << ")";
}
