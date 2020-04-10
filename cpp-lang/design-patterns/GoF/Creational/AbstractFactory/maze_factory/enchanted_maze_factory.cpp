#include "enchanted_maze_factory.h"

#include "door_needing_spell.h"
#include "enchanted_room.h"

std::shared_ptr<Maze> EnchantedMazeFactory::make_maze() const {
    return std::make_shared<Maze>();
}

std::shared_ptr<Room> EnchantedMazeFactory::make_room(int rn) const {
    return std::make_shared<EnchantedRoom>(rn);
}

std::shared_ptr<Wall> EnchantedMazeFactory::make_wall() const {
    return std::make_shared<Wall>();
}

std::shared_ptr<Door> EnchantedMazeFactory::make_door(std::weak_ptr<Room> r1,
                                                      std::weak_ptr<Room> r2) const {
    return std::make_shared<DoorNeedingSpell>(r1, r2);
}
