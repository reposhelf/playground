#include "inventory.h"
#include "instrument.h"
#include "instrumentspec.h"

#include <algorithm>

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

void Inventory::addInstrument(const std::string &serialNumber, double price, InstrumentSpec *spec)
{
    mInventory.push_back(new Instrument(serialNumber, price, spec));
}

Instrument *Inventory::get(const std::string &serialNumber) const
{
    for (Instrument *i : mInventory) {
        if (i->getSerialNumber() == serialNumber)
            return i;
    }
    return nullptr;
}

std::vector<Instrument *> Inventory::search(const InstrumentSpec &searchSpec) const
{
    std::vector<Instrument *> matchingInstruments;
    auto searchSpecProperties = searchSpec.getProperties();
    for (Instrument *i : mInventory) {
        auto instrumentSpec = i->getSpec();
        auto instrumentProperties = instrumentSpec->getProperties();
        if (std::includes(instrumentProperties.begin(), instrumentProperties.end(),
                          searchSpecProperties.begin(), searchSpecProperties.end())) {
            matchingInstruments.push_back(i);
        }
    }
    return matchingInstruments;
}
