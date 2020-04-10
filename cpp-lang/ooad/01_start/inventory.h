#ifndef INVENTORY_H
#define INVENTORY_H

#include "type.h"
#include "builder.h"
#include "wood.h"

#include <vector>
#include <string>

class Guitar;
class GuitarSpec;
class Inventory
{
public:
    Inventory();
    ~Inventory();

    void addGuitar(Guitar *guitar);
    Guitar *guitar(const std::string &serialNumber) const;
    std::vector<Guitar *> search(const GuitarSpec &searchSpec) const;

private:
    std::vector<Guitar *> m_guitars;
};

#endif // INVENTORY_H
