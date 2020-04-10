#include "point.h"

#include <cmath>

float distance(Point a, Point b)
{
    float dx = a.x - b.x;
    float dy = a.y - b.y;

    return sqrt(dx * dx + dy * dy);
}

void polar(float x, float y, float &r, float &theta)
{
    r = sqrt(x * x + y * y);
    theta = atan2(x, y);
}