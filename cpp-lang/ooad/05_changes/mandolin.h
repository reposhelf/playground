#ifndef MANDOLIN_H
#define MANDOLIN_H

#include "instrument.h"

class MandolinSpec;
class Mandolin : public Instrument
{
public:
    Mandolin(const std::string &serialNumber, double price, MandolinSpec *spec);
    ~Mandolin();
};

#endif // MANDOLIN_H
