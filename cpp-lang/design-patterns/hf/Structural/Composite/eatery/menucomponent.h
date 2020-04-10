#ifndef MENUCOMPONENT_H
#define MENUCOMPONENT_H

#include <string>

class MenuComponent
{
public:
    MenuComponent();
    virtual ~MenuComponent();

    virtual std::string getName() const;
    virtual std::string getDescription() const;
    virtual bool isVegetarian() const;
    virtual float getPrice() const;

    virtual void add(MenuComponent *menuComponent);
    virtual void remove(MenuComponent *menuComponent);
    virtual MenuComponent *getChild(size_t i) const;

    virtual void print() const;
};

#endif // MENUCOMPONENT_H
