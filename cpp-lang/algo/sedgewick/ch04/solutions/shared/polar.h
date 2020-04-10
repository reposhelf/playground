#ifndef POLAR_H
#define POLAR_H

#include <ostream>

class Polar
{
public:
    Polar();

    float distance(const Polar &other) const;

    float radius() const { return _radius; }
    float angle() const { return _angle; }

private:
    float _radius;
    float _angle;
};

std::ostream &operator<<(std::ostream &os, const Polar &p);

#endif // POLAR_H
