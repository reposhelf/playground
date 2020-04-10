#ifndef ENCHANTEDMAZEGAME_H
#define ENCHANTEDMAZEGAME_H

#include "mazegame.h"


class EnchantedMazeGame : public MazeGame
{
public:
    virtual std::shared_ptr<Door> make_door(std::weak_ptr<Room>, std::weak_ptr<Room>) const;
    std::shared_ptr<Room> make_room(int) const override;
};

#endif // ENCHANTEDMAZEGAME_H
