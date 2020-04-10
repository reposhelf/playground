#ifndef CLAMPIZZA_H
#define CLAMPIZZA_H

#include "pizza.h"

class ClamPizza : public Pizza
{
public:
    ClamPizza();
    ~ClamPizza();

    void prepare();
    void bake();
    void cut();
    void box();
};

#endif // CLAMPIZZA_H
