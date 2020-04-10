#ifndef POINT_H
#define POINT_H

class Point
{
public:
    Point();
    Point(double x, double y);

    void setX(double x);
    double x() const { return _x; }

    void setY(double y);
    double y() const { return _y; }

    double distanceTo(double x, double y) const;
    double distanceTo(const Point &other) const;

private:
    double _x;
    double _y;
};

#endif // POINT_H