#include "guitar.h"
#include "guitarspec.h"

Guitar::Guitar(const std::string &serialNumber, double price, GuitarSpec *spec)
    : Instrument(serialNumber, price, spec)
{

}

Guitar::~Guitar()
{

}
