#include "board.h"
#include "unit.h"

#include <iostream>

int main()
{
    Board board(8, 8);
    board.add_unit(std::shared_ptr<Unit>(new Unit()), 8, 8);
    board.add_unit(std::shared_ptr<Unit>(new Unit()), 8, 8);
    std::cout << (board.get_units(1, 1).size()) << std::endl;
    std::cout << (board.get_units(8, 8).size()) << std::endl;
    board.remove_units(8, 8);
    std::cout << (board.get_units(8, 8).size()) << std::endl;
    return 0;
}
