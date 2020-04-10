#ifndef WAITRESS_H
#define WAITRESS_H

class MenuComponent;
class Waitress
{
public:
    Waitress(MenuComponent *menu);

    void printMenu();

private:
    MenuComponent *m_menu;
};

#endif // WAITRESS_H
