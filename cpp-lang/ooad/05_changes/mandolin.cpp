#include "mandolin.h"
#include "mandolinspec.h"

Mandolin::Mandolin(const std::string &serialNumber, double price, MandolinSpec *spec)
    : Instrument(serialNumber, price, spec)
{

}

Mandolin::~Mandolin()
{

}
