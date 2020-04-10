#include "doorneedingspell.h"


DoorNeedingSpell::DoorNeedingSpell(std::weak_ptr<Room> r1, std::weak_ptr<Room> r2)
    : Door(r1, r2)
{
    // Empty
}

void DoorNeedingSpell::enter()
{
    // Empty
}
