#include "dinermenu.h"
#include "menuitem.h"
#include "dinermenuiterator.h"

#include <iostream>
using std::cout;
using std::endl;

using std::shared_ptr;

DinerMenu::DinerMenu()
    : Menu()
{
    addMenuItem("Vegetarian BLT",
                "(Fakin) Bacon with lettuce & tomato on whole wheat",
                true,
                2.99);
    addMenuItem("BLT",
                "Bacon with lettuce & tomato on whole wheat",
                false,
                2.99);
    addMenuItem("Soup of the day",
                "Soup of the day, with a side of potato salad",
                false,
                3.29);
    addMenuItem("Hotdog",
                "A hot dog, with saurkraut, relish, onions, topped with cheese",
                false,
                3.05);
}

DinerMenu::~DinerMenu()
{
    for (int i = 0; i < MAX_ITEMS; ++i)
        delete _items[i];
}

std::shared_ptr<Iterator> DinerMenu::createIterator()
{
    return shared_ptr<Iterator>(new DinerMenuIterator(_items, MAX_ITEMS));
}

std::string DinerMenu::title() const
{
    return "\nLUNCH";
}

void DinerMenu::addMenuItem(const std::string &name,
                            const std::string &description,
                            bool isVegetarian,
                            float price)
{
    static int currentItemIndex = 0;
    if (currentItemIndex >= MAX_ITEMS)
        cout << "Sorry, menu is full! Cann't add item to menu" << endl;
    else
        _items[currentItemIndex++] = new MenuItem(name, description, isVegetarian, price);
}
