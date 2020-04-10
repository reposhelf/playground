#ifndef POINT_H
#define POINT_H

#include <ostream>

class Point
{
public:
    Point();
    Point(float x, float y);

    float distance(const Point &other) const;
    float distance(float x, float y) const;
    float distance() const;

    float x() const { return _x; }
    void setX(float x);

    float y() const { return _y; }
    void setY(float y);

    bool operator==(const Point &other) const;
    bool operator!=(const Point &other) const;

private:
    float _x;
    float _y;
};

std::ostream &operator<<(std::ostream &os, const Point &p);

#endif // POINT_H
