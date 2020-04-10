#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>

class MenuItem
{
public:
    MenuItem(const std::string &name,
             const std::string &description,
             bool vegetarian,
             float price);

    std::string name() const { return _name; }
    void setName(const std::string &name);

    std::string description() const { return _description; }
    void setDescription(const std::string &description);

    bool isVegetarian() const { return _isVegetarian; }
    void setVegetarian(bool isVegetarian);

    float price() const { return _price; }
    void setPrice(float price);

private:
    std::string _name;
    std::string _description;
    bool _isVegetarian;
    float _price;
};

#endif // MENUITEM_H
