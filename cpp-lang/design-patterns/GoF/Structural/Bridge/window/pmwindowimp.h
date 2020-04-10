#ifndef PMWINDOWIMP_H
#define PMWINDOWIMP_H

#include "windowimp.h"

class PMWindowImp : public WindowImp
{
public:
    PMWindowImp();

    void impTop() override;
    void impBottom() override;
    void impSetExtent(const Point&) override;
    void setOrigin(const Point&) override;

    void deviceRect(Coord, Coord, Coord, Coord) override;
    void deviceText(const char*, Coord, Coord) override;
    void deviceBitmap(const char*, Coord, Coord) override;
};

#endif // PMWINDOWIMP_H
