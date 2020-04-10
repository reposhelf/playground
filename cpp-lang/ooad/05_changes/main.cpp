#include "inventory.h"
#include "instrument.h"
#include "guitar.h"
#include "guitarspec.h"

#include <iostream>
#include <vector>

#include <QCoreApplication>

using std::cout;
using std::endl;
using std::vector;

void initInventory(Inventory &inventory)
{
    inventory.addInstrument("V95693", 1499.95, new GuitarSpec(Builder::Fender,
                                                              "Stratocastor",
                                                              Type::Electric,
                                                              6,
                                                              Wood::Alder,
                                                              Wood::Alder));
    inventory.addInstrument("V9512", 1549.95, new GuitarSpec(Builder::Fender,
                                                             "Stratocastor",
                                                             Type::Electric,
                                                             6,
                                                             Wood::Alder,
                                                             Wood::Alder));
}

int main()
{
    Inventory inventory;
    initInventory(inventory);

    GuitarSpec whatErinLikes(Builder::Fender, "Stratocastor",
                             Type::Electric, 6, Wood::Alder, Wood::Alder);

    vector<Instrument *> matchingGuitars = inventory.search(whatErinLikes);
    if (!matchingGuitars.empty()) {
        cout << "Erin, you might like these guitars:" << endl;
        for (Instrument *guitar : matchingGuitars) {
            GuitarSpec *spec = dynamic_cast<GuitarSpec *>(guitar->getSpec());
            if (spec) {
                cout << "  We have a " << builderToString(spec->getBuilder()) << " "
                     << spec->getModel() << " " << typeToString(spec->getType()) << " guitar:\n    "
                     << woodToString(spec->getBackWood()) + " back and sides, \n    "
                     << woodToString(spec->getTopWood()) << " top.\n  You can have it for only $"
                     << guitar->getPrice() << "!\n----" << endl;
            }
        }
    } else {
        cout << "Sorry, Erin, we have nothing for you" << endl;
    }

    return 0;
}
