#ifndef ENCHANTED_ROOM_H
#define ENCHANTED_ROOM_H

#include "room.h"

class EnchantedRoom : public Room {
public:
    explicit EnchantedRoom(int);
    void enter() override;
};

#endif
