#ifndef POINT_H
#define POINT_H

class Point
{
public:
    Point();
    float distance(const Point &other) const;

private:
    float _x;
    float _y;
};

#endif // POINT_H
