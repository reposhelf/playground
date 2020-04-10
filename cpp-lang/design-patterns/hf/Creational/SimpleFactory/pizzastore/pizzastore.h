#ifndef PIZZASTORE_H
#define PIZZASTORE_H

#include "simplepizzafactory.h"

class Pizza;
class PizzaStore
{
public:
    PizzaStore(SimplePizzaFactory *factory);

    Pizza *orderPizza(SimplePizzaFactory::PizzaType);

private:
    SimplePizzaFactory *m_factory;
};

#endif // PIZZASTORE_H
