#include "guitar.h"

using std::string;

Guitar::Guitar(const string &serialNumber, double price, const GuitarSpec &spec)
    : m_serialNumber(serialNumber),
      m_price(price),
      m_spec(spec)
{

}
