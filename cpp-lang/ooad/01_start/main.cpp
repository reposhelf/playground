#include "guitar.h"
#include "inventory.h"

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void initInventory(Inventory &inventory)
{
    inventory.addGuitar(new Guitar("V95693", 1499.95, GuitarSpec(Builder::Fender, "Stratocastor",
                        Type::Electric, Wood::Alder, Wood::Alder, 6)));
    inventory.addGuitar(new Guitar("V9512", 1549.95, GuitarSpec(Builder::Fender, "Stratocastor",
                        Type::Electric, Wood::Alder, Wood::Alder, 6)));
}

int main()
{
    Inventory inventory;
    initInventory(inventory);

    GuitarSpec whatErinLikes(Builder::Fender, "Stratocastor",
                             Type::Electric, Wood::Alder, Wood::Alder, 6);

    vector<Guitar *> matchingGuitars = inventory.search(whatErinLikes);
    if (!matchingGuitars.empty()) {
        cout << "Erin, you might like these guitars:" << endl;
        for (Guitar *guitar : matchingGuitars) {
            GuitarSpec spec = guitar->spec();
            cout << "  We have a " << Builder::toString(spec.builder()) << " "
                 << spec.model() << " " << Type::toString(spec.type()) << " guitar:\n    "
                 << Wood::toString(spec.backWood()) + " back and sides, \n    "
                 << Wood::toString(spec.topWood()) << " top.\n  You can have it for only $"
                 << guitar->price() << "!\n----" << endl;
        }
    } else {
        cout << "Sorry, Erin, we have nothing for you" << endl;
    }

    return 0;
}
