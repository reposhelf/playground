#ifndef GUITAR_H
#define GUITAR_H

#include "instrument.h"

class GuitarSpec;
class Guitar : public Instrument
{
public:
    Guitar(const std::string &serialNumber, double price, GuitarSpec *spec);
    ~Guitar();
};

#endif // GUITAR_H
