#ifndef DOOR_NEEDING_SPELL_H
#define DOOR_NEEDING_SPELL_H

#include <memory>

#include "door.h"
#include "room.h"

class DoorNeedingSpell : public Door {
public:
    DoorNeedingSpell(std::weak_ptr<Room>, std::weak_ptr<Room>);
    void enter() override;
};

#endif
