#include "inventory.h"
#include "guitar.h"
#include "mandolin.h"
#include "guitarspec.h"
#include "mandolinspec.h"
#include "instrument.h"

using std::string;
using std::vector;

Inventory::Inventory()
{

}

Inventory::~Inventory()
{
    for (Instrument *i : mInventory)
        delete i;
}

void Inventory::addInstrument(const std::string &serialNumber, double price, GuitarSpec *spec)
{
    mInventory.push_back(new Guitar(serialNumber, price, spec));
}

void Inventory::addInstrument(const std::string &serialNumber, double price, MandolinSpec *spec)
{
    mInventory.push_back(new Mandolin(serialNumber, price, spec));
}

Instrument *Inventory::get(const std::string &serialNumber) const
{
    for (Instrument *i : mInventory) {
        if (i->getSerialNumber() == serialNumber)
            return i;
    }
    return nullptr;
}

std::vector<Instrument *> Inventory::search(const GuitarSpec &searchSpec) const
{
    std::vector<Instrument *> matchingGuitars;
    for (Instrument *i : mInventory) {
        GuitarSpec *spec = dynamic_cast<GuitarSpec *>(i->getSpec());
        if (spec) {
            if (*spec == searchSpec)
                matchingGuitars.push_back(i);
        }
    }
    return matchingGuitars;
}

std::vector<Instrument *> Inventory::search(const MandolinSpec &searchSpec) const
{
    std::vector<Instrument *> matchingMandolins;
    for (Instrument *i : mInventory) {
        GuitarSpec *spec = dynamic_cast<GuitarSpec *>(i->getSpec());
        if (spec) {
            if (*spec == searchSpec)
                matchingMandolins.push_back(i);
        }
    }
    return matchingMandolins;
}
