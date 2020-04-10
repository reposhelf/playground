#ifndef NYPIZZASTORE_H
#define NYPIZZASTORE_H

#include "pizzastore.h"

class NyPizzaStore : public PizzaStore
{
public:
    NyPizzaStore();
    ~NyPizzaStore();

private:
    Pizza *createPizza(PizzaType) const;
};

#endif // NYPIZZASTORE_H
