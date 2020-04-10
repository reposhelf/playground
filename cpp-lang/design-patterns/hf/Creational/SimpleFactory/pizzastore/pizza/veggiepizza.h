#ifndef VEGGIEPIZZA_H
#define VEGGIEPIZZA_H

#include "pizza.h"

class VeggiePizza : public Pizza
{
public:
    VeggiePizza();
    ~VeggiePizza();

    void prepare();
    void bake();
    void cut();
    void box();
};

#endif // VEGGIEPIZZA_H
