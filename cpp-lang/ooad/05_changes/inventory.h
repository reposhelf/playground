#ifndef INVENTORY_H
#define INVENTORY_H

#include "type.h"
#include "builder.h"
#include "wood.h"

#include <vector>
#include <string>

class Instrument;
class GuitarSpec;
class MandolinSpec;
class Inventory
{
public:
    Inventory();
    ~Inventory();

    void addInstrument(const std::string &serialNumber, double price, GuitarSpec *spec);
    void addInstrument(const std::string &serialNumber, double price, MandolinSpec *spec);
    Instrument *get(const std::string &serialNumber) const;
    std::vector<Instrument *> search(const GuitarSpec &searchSpec) const;
    std::vector<Instrument *> search(const MandolinSpec &searchSpec) const;

private:
    std::vector<Instrument *> mInventory;
};

#endif // INVENTORY_H
