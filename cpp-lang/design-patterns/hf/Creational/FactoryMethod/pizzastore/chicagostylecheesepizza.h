#ifndef CHICAGOSTYLECHEESEPIZZA_H
#define CHICAGOSTYLECHEESEPIZZA_H

#include "pizza.h"

class ChicagoStyleCheesePizza : public Pizza
{
public:
    ChicagoStyleCheesePizza();
    ~ChicagoStyleCheesePizza();

    void cut() const;

private:
    void initialize();
};

#endif // CHICAGOSTYLECHEESEPIZZA_H
