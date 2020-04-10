#include <iostream>

#include "bus.h"
#include "cabinet.h"
#include "card.h"
#include "chassis.h"
#include "floppy_disk.h"

int main() {
    Cabinet cabinet("PC Cabinet");
    cabinet.set_net_price(20.0);

    std::cout << cabinet.net_price() << '\n';

    Chassis *chassis = new Chassis("PC Chassis");
    chassis->set_net_price(10.0);

    cabinet.add(chassis);
    std::cout << cabinet.net_price() << '\n';

    Bus *bus = new Bus("MCA Bus");
    bus->set_net_price(15.0);

    Card *card = new Card("16Mbs Token Ring");
    card->set_net_price(25.0);

    bus->add(card);

    chassis->add(bus);

    FloppyDisk *floppy = new FloppyDisk("3.5in Floppy");
    floppy->set_net_price(5.0);

    chassis->add(floppy);

    std::cout << cabinet.net_price() << '\n';

    bus->remove(card);
    chassis->remove(floppy);

    std::cout << cabinet.net_price() << '\n';

    return 0;
}
