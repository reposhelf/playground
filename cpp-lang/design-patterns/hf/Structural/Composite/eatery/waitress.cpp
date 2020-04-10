#include "waitress.h"
#include "menucomponent.h"

Waitress::Waitress(MenuComponent *menu)
    : m_menu(menu)
{
}

void Waitress::printMenu()
{
    m_menu->print();
}
