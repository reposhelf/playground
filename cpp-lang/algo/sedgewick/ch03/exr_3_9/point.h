#ifndef POINT_H
#define POINT_H

#include <ostream>

class Point
{
    friend std::ostream &operator<<(std::ostream &out, const Point &p);

public:
    explicit Point();
    explicit Point(double x, double y);

    void setX(double x);
    double x() const { return _x; }

    void setY(double y);
    double y() const { return _y; }

    double distanceTo(double x, double y) const;
    double distanceTo(const Point &other) const;

    bool isSameLine(double x1, double y1, double x2, double y2) const;
    bool isSameLine(const Point &p1, const Point &p2) const;

private:
    double _x;
    double _y;
};

#endif // POINT_H