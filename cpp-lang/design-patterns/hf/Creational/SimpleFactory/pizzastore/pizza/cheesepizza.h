#ifndef CHEESEPIZZA_H
#define CHEESEPIZZA_H

#include "pizza.h"

class CheesePizza : public Pizza
{
public:
    CheesePizza();
    ~CheesePizza();

    void prepare();
    void bake();
    void cut();
    void box();
};

#endif // CHEESEPIZZA_H
