#include "xwindowimp.h"

#include <iostream>

XWindowImp::XWindowImp()
    : WindowImp()
{
    std::cout << __func__ << std::endl;
}

void XWindowImp::impTop()
{
    // Empty
}

void XWindowImp::impBottom()
{
    // Empty
}

void XWindowImp::impSetExtent(const Point &)
{
    // Empty
}

void XWindowImp::setOrigin(const Point &)
{
    // Empty
}

void XWindowImp::deviceRect(Coord, Coord, Coord, Coord)
{
    std::cout << "XWindowImp::deviceRect(Coord, Coord, Coord, Coord)" << std::endl;
}

void XWindowImp::deviceText(const char *, Coord, Coord)
{
    // Empty
}

void XWindowImp::deviceBitmap(const char *, Coord, Coord)
{
    // Empty
}
