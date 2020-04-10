#include "pancakehousemenu.h"
#include "menuitem.h"
#include "pancakehouseiterator.h"

using std::shared_ptr;

PancakeHouseMenu::PancakeHouseMenu()
    : Menu(),
      _items()
{
    _items.push_back(new MenuItem("K&B's Pancake Breakfast",
                                  "Pancakes with scrambled eggs, and toast",
                                  true,
                                  2.99));
    _items.push_back(new MenuItem("Regular Pancake Breakfast",
                                  "Pancakes with fried eggs, sausage",
                                  false,
                                  2.99));
    _items.push_back(new MenuItem("Blueberry Pancakes",
                                  "Pankaces made with fresh blueberries",
                                  true,
                                  3.49));
    _items.push_back(new MenuItem("Waffles",
                                  "Waffles, with your choice of blueberries or strawberries",
                                  true,
                                  3.59));
}

PancakeHouseMenu::~PancakeHouseMenu()
{
    for (auto i : _items)
        delete i;
}

std::shared_ptr<Iterator> PancakeHouseMenu::createIterator()
{
    return shared_ptr<Iterator>(new PancakeHouseIterator(_items));
}

std::string PancakeHouseMenu::title() const
{
    return "\nBREAKFAST";
}
