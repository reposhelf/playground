#ifndef PEPPERONIPIZZA_H
#define PEPPERONIPIZZA_H

#include "pizza.h"

class PepperoniPizza : public Pizza
{
public:
    PepperoniPizza();
    ~PepperoniPizza();

    void prepare();
    void bake();
    void cut();
    void box();
};

#endif // PEPPERONIPIZZA_H
