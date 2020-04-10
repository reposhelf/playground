#include "menuitem.h"

MenuItem::MenuItem(const std::string &name,
                   const std::string &description,
                   bool vegetarian,
                   float price)
    : _name(name),
      _description(description),
      _isVegetarian(vegetarian),
      _price(price)
{
}

void MenuItem::setName(const std::string &name)
{
    _name = name;
}

void MenuItem::setDescription(const std::string &description)
{
    _description = description;
}

void MenuItem::setVegetarian(bool isVegetarian)
{
    _isVegetarian = isVegetarian;
}

void MenuItem::setPrice(float price)
{
    _price = price;
}
