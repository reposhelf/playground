#ifndef GUITAR_H
#define GUITAR_H

#include "type.h"
#include "builder.h"
#include "wood.h"
#include "guitarspec.h"

#include <string>

class Guitar
{
public:
    Guitar(const std::string &serialNumber, double price, const GuitarSpec &spec);

    std::string serialNumber() const { return m_serialNumber; }
    double price() const { return m_price; }
    void setPrice(double newPrice) { m_price = newPrice; }
    GuitarSpec spec() const { return m_spec; }

private:
    std::string m_serialNumber;
    double m_price;
    GuitarSpec m_spec;
};

#endif // GUITAR_H
