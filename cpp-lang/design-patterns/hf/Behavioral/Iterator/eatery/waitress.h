#ifndef WAITRESS_H
#define WAITRESS_H

#include <vector>

class Menu;
class Iterator;
class Waitress
{
public:
    Waitress(const std::vector<Menu *> menus);

    void printMenu() const;

private:
    void printMenu(Iterator *iterator) const;

    std::vector<Menu *> _menus;
};

#endif // WAITRESS_H
