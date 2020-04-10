#ifndef ENCHANTEDROOM_H
#define ENCHANTEDROOM_H

#include "room.h"


class EnchantedRoom : public Room
{
public:
    explicit EnchantedRoom(int);
    void enter() override;
};

#endif // ENCHANTEDROOM_H
