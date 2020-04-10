#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <string>

class InstrumentSpec;
class Instrument
{
public:
    Instrument(const std::string &serialNumber, double price, InstrumentSpec *spec);
    virtual ~Instrument();

    std::string getSerialNumber() const { return mSerialNumber; }
    InstrumentSpec *getSpec() const { return mSpec; }
    double getPrice() const { return mPrice; }
    void setPrice(double newPrice) { mPrice = newPrice; }

private:
    std::string mSerialNumber;
    double mPrice;
    InstrumentSpec *mSpec;
};

#endif // INSTRUMENT_H
