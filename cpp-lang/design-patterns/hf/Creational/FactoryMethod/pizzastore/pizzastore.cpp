#include "pizzastore.h"
#include "pizza.h"

PizzaStore::PizzaStore()
{
}

PizzaStore::~PizzaStore()
{
}

Pizza *PizzaStore::orderPizza(PizzaType type) const
{
    Pizza *pizza = createPizza(type);
    if (!pizza)
        return nullptr;

    pizza->prepare();
    pizza->bake();
    pizza->cut();
    pizza->box();

    return pizza;
}
