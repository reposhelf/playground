#ifndef PANCAKEHOUSEMENU_H
#define PANCAKEHOUSEMENU_H

#include "menu.h"

#include <vector>

class MenuItem;
class Iterator;
class PancakeHouseMenu : public Menu
{
public:
    PancakeHouseMenu();
    ~PancakeHouseMenu();

    std::shared_ptr<Iterator> createIterator();
    std::string title() const;

private:
    std::vector<MenuItem *> _items;
};

#endif // PANCAKEHOUSEMENU_H
