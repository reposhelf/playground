#ifndef POINT_H
#define POINT_H

struct Point
{
    float x;
    float y;
};

float distance(Point a, Point b);
void polar(float x, float y, float &r, float &theta);

#endif // POINT_H