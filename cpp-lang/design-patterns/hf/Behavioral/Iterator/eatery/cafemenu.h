#ifndef CAFEMENU_H
#define CAFEMENU_H

#include "menu.h"

#include <list>

class MenuItem;
class CafeMenu : public Menu
{
public:
    CafeMenu();
    ~CafeMenu();

    std::shared_ptr<Iterator> createIterator();
    std::string title() const;

private:
    std::list<MenuItem *> _items;
};

#endif // CAFEMENU_H
