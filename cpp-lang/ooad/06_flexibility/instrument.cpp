#include "instrument.h"
#include "instrumentspec.h"

Instrument::Instrument(const std::string &serialNumber, double price, InstrumentSpec *spec)
    : mSerialNumber(serialNumber),
      mPrice(price),
      mSpec(spec)
{
}

Instrument::~Instrument()
{
    delete mSpec;
}
