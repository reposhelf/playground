#ifndef MENU_H
#define MENU_H

#include "menucomponent.h"

#include <list>

class Menu : public MenuComponent
{
public:
    Menu(const std::string &name, const std::string &description);
    ~Menu() override;

    std::string getName() const override { return m_name; }
    std::string getDescription() const override { return m_description; }

    void add(MenuComponent *menuComponent) override;
    void remove(MenuComponent *menuComponent) override;
    MenuComponent *getChild(size_t i) const override;

    void print() const override;

private:
    std::string m_name;
    std::string m_description;
    std::list<MenuComponent *> m_menuComponents;
};

#endif // MENU_H
