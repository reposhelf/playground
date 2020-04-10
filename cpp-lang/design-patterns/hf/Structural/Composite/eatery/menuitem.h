#ifndef MENUITEM_H
#define MENUITEM_H

#include "menucomponent.h"

class MenuItem : public MenuComponent
{
public:
    MenuItem(const std::string &name,
             const std::string &description,
             bool isVegetarian,
             float price);

    std::string getName() const override { return m_name; }
    std::string getDescription() const override { return m_description; }
    bool isVegetarian() const override { return m_isVegetarian; }
    float getPrice() const override { return m_price; }
    void print() const override;

private:
    std::string m_name;
    std::string m_description;
    bool m_isVegetarian;
    float m_price;
};

#endif // MENUITEM_H
