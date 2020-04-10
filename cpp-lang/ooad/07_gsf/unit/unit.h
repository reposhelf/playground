#ifndef UNIT_H
#define UNIT_H

#include "unit_global.h"

class UNITSHARED_EXPORT Unit
{

public:
    Unit();
    Unit(const Unit&) = delete;
    Unit& operator=(const Unit&) = delete;
};

#endif // UNIT_H
