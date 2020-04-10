#include "inventory.h"
#include "guitar.h"
#include "guitarspec.h"

using std::string;
using std::vector;

Inventory::Inventory()
{

}

Inventory::~Inventory()
{
    for (Guitar *g : m_guitars)
        delete g;
}

void Inventory::addGuitar(Guitar *guitar)
{
    m_guitars.push_back(guitar);
}

Guitar *Inventory::guitar(const std::string &serialNumber) const
{
    for (Guitar *g : m_guitars) {
        if (g->serialNumber() == serialNumber)
            return g;
    }
    return nullptr;
}

std::vector<Guitar *> Inventory::search(const GuitarSpec &searchSpec) const
{
    vector<Guitar *> matchingGuitars;

    for (Guitar *guitar : m_guitars) {
        if (guitar->spec() == searchSpec)
            matchingGuitars.push_back(guitar);
    }
    return matchingGuitars;
}
