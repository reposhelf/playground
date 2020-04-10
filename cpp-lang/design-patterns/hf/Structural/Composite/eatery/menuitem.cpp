#include "menuitem.h"

#include <iostream>
using std::cout;
using std::endl;

MenuItem::MenuItem(const std::string &name,
                   const std::string &description,
                   bool isVegetarian,
                   float price)
    : MenuComponent(),
      m_name(name),
      m_description(description),
      m_isVegetarian(isVegetarian),
      m_price(price)
{
}

void MenuItem::print() const
{
    cout << " " << getName();
    if (isVegetarian())
        cout << "(v)";
    cout << ", " << getPrice() << endl;
    cout << "  -- " << getDescription() << endl;
}
