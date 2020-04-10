#ifndef CHICAGOPIZZASTORE_H
#define CHICAGOPIZZASTORE_H

#include "pizzastore.h"

class ChicagoPizzaStore : public PizzaStore
{
public:
    ChicagoPizzaStore();
    ~ChicagoPizzaStore();

private:
    Pizza *createPizza(PizzaType) const;
};

#endif // CHICAGOPIZZASTORE_H
