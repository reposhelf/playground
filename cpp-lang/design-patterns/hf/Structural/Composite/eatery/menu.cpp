#include "menu.h"

#include <cassert>
#include <iostream>
using std::cout;
using std::endl;

Menu::Menu(const std::string &name, const std::string &description)
    : MenuComponent(),
      m_name(name),
      m_description(description),
      m_menuComponents()
{
}

Menu::~Menu()
{
    for (auto it = m_menuComponents.cbegin(); it != m_menuComponents.cend(); ++it)
        delete *it;
}

void Menu::add(MenuComponent *menuComponent)
{
    m_menuComponents.push_back(menuComponent);
}

void Menu::remove(MenuComponent *menuComponent)
{
    m_menuComponents.remove(menuComponent);
}

MenuComponent *Menu::getChild(size_t i) const
{
    assert(i < m_menuComponents.size());

    auto it = m_menuComponents.begin();
    std::advance(it, i);
    return *it;
}

void Menu::print() const
{
    cout << getName() << ", " << getDescription() << endl;
    std::string lines(10, '-');
    cout << lines << endl;

    for (auto it = m_menuComponents.cbegin(); it != m_menuComponents.cend(); ++it)
        (*it)->print();
}
