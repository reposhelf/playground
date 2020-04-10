#ifndef DOORNEEDINGSPELL_H
#define DOORNEEDINGSPELL_H

#include <memory>

#include "door.h"
#include "room.h"


class DoorNeedingSpell : public Door
{
public:
    DoorNeedingSpell(std::weak_ptr<Room>, std::weak_ptr<Room>);
    void enter() override;
};

#endif // DOORNEEDINGSPELL_H
