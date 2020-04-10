#ifndef SHAPE_H
#define SHAPE_H

#include <memory>

struct Point {
    int x;
    int y;
    Point(int _x, int _y)
        : x(_x), y(_y) {}
};

class Shape;
struct Manipulator {
public:
    explicit Manipulator(Shape *shape)
        : shape_(shape) {}

private:
    Shape *shape_;
};

class Shape {
public:
    Shape();
    virtual ~Shape();

    virtual void bounding_box(Point &bottom_left, Point &top_right) const = 0;
    virtual std::shared_ptr<Manipulator> create_manipulator() const = 0;
};

#endif
