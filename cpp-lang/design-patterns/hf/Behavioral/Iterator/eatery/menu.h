#ifndef MENU_H
#define MENU_H

#include <string>
#include <memory>

class Iterator;
class Menu
{
public:
    Menu();
    virtual ~Menu();

    virtual std::shared_ptr<Iterator> createIterator() = 0;
    virtual std::string title() const = 0;
};

#endif // MENU_H
