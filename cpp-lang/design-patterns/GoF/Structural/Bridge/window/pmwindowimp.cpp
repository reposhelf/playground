#include "pmwindowimp.h"

#include <iostream>

PMWindowImp::PMWindowImp()
    : WindowImp()
{
    std::cout << __func__ << std::endl;
}

void PMWindowImp::impTop()
{
    // Empty
}

void PMWindowImp::impBottom()
{
    // Empty
}

void PMWindowImp::impSetExtent(const Point &)
{
    // Empty
}

void PMWindowImp::setOrigin(const Point &)
{
    // Empty
}

void PMWindowImp::deviceRect(Coord, Coord, Coord, Coord)
{
    std::cout << "PMWindowImp::deviceRect(Coord, Coord, Coord, Coord)" << std::endl;
}

void PMWindowImp::deviceText(const char *, Coord, Coord)
{
    // Empty
}

void PMWindowImp::deviceBitmap(const char *, Coord, Coord)
{
    // Empty
}

