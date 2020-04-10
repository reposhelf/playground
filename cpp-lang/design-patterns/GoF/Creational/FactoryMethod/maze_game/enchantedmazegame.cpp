#include "enchantedmazegame.h"

#include "enchantedroom.h"
#include "doorneedingspell.h"


std::shared_ptr<Door> EnchantedMazeGame::make_door(std::weak_ptr<Room> r1,
                                                   std::weak_ptr<Room> r2) const
{
    return std::make_shared<DoorNeedingSpell>(r1, r2);
}

std::shared_ptr<Room> EnchantedMazeGame::make_room(int rn) const
{
    return std::make_shared<EnchantedRoom>(rn);
}
