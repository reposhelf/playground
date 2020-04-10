#ifndef INVENTORY_H
#define INVENTORY_H

#include "type.h"
#include "builder.h"
#include "wood.h"

#include <vector>
#include <string>

class Instrument;
class InstrumentSpec;
class Inventory
{
public:
    Inventory();
    ~Inventory();

    void addInstrument(const std::string &serialNumber, double price, InstrumentSpec *spec);
    Instrument *get(const std::string &serialNumber) const;
    std::vector<Instrument *> search(const InstrumentSpec &searchSpec) const;

private:
    std::vector<Instrument *> mInventory;
};

#endif // INVENTORY_H
