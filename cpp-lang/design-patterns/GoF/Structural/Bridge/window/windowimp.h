#ifndef WINDOWIMP_H
#define WINDOWIMP_H

#include <utility>

using Point = std::pair<int, int>;
using Coord = int;

class WindowImp
{
public:
    virtual void impTop() = 0;
    virtual void impBottom() = 0;
    virtual void impSetExtent(const Point&) = 0;
    virtual void setOrigin(const Point&) = 0;

    virtual void deviceRect(Coord, Coord, Coord, Coord) = 0;
    virtual void deviceText(const char*, Coord, Coord) = 0;
    virtual void deviceBitmap(const char*, Coord, Coord) = 0;

protected:
    WindowImp() = default;
};

#endif // WINDOWIMP_H
