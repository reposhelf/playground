#ifndef WILDTURKEY_H
#define WILDTURKEY_H

#include "turkey.h"

class WildTurkey : public Turkey
{
public:
    WildTurkey();
    ~WildTurkey();

    void gobble() const;
    void fly() const;
};

#endif // WILDTURKEY_H
