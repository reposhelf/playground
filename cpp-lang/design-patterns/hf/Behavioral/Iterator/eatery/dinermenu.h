#ifndef DINERMENU_H
#define DINERMENU_H

#include "menu.h"

class MenuItem;
class Iterator;
class DinerMenu : public Menu
{
public:
    DinerMenu();
    ~DinerMenu();

    std::shared_ptr<Iterator> createIterator();
    std::string title() const;

private:
    void addMenuItem(const std::string &name,
                     const std::string &description,
                     bool isVegetarian,
                     float price);

    static const int MAX_ITEMS = 4;
    MenuItem *_items[MAX_ITEMS];
};

#endif // DINERMENU_H
