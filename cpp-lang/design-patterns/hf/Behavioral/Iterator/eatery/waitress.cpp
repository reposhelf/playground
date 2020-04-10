#include "waitress.h"
#include "iterator.h"
#include "dinermenu.h"
#include "pancakehousemenu.h"
#include "menuitem.h"

#include <iostream>
using std::cout;
using std::endl;

#include <memory>
using std::shared_ptr;

Waitress::Waitress(const std::vector<Menu *> menus)
    : _menus(menus)
{
}

void Waitress::printMenu() const
{
    cout << "MENU" << endl;
    cout << "----" << endl;

    for (auto m : _menus) {
        cout << m->title() << endl;
        printMenu(m->createIterator().get());
    }
}

void Waitress::printMenu(Iterator *iterator) const
{
    while (iterator->hasNext()) {
        MenuItem *item = iterator->next();
        cout << item->name() << ", ";
        cout << item->price() << " -- ";
        cout << item->description() << endl;
    }
}
