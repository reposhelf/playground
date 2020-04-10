#ifndef XWINDOWIMP_H
#define XWINDOWIMP_H

#include "windowimp.h"

class XWindowImp : public WindowImp
{
public:
    XWindowImp();

    void impTop() override;
    void impBottom() override;
    void impSetExtent(const Point&) override;
    void setOrigin(const Point&) override;

    void deviceRect(Coord, Coord, Coord, Coord) override;
    void deviceText(const char*, Coord, Coord) override;
    void deviceBitmap(const char*, Coord, Coord) override;
};

#endif // XWINDOWIMP_H
