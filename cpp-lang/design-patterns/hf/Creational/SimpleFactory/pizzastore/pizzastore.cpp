#include "pizzastore.h"
#include "simplepizzafactory.h"
#include "pizza.h"

PizzaStore::PizzaStore(SimplePizzaFactory *factory)
    : m_factory(factory)
{
}

Pizza *PizzaStore::orderPizza(SimplePizzaFactory::PizzaType type)
{
    if (!m_factory)
        return nullptr;

    Pizza *pizza = m_factory->createPizza(type);
    if (!pizza)
        return nullptr;

    pizza->prepare();
    pizza->bake();
    pizza->cut();
    pizza->box();

    return pizza;
}
