#include "nypizzastore.h"
#include "nystylecheesepizza.h"

NyPizzaStore::NyPizzaStore()
    : PizzaStore()
{
}

NyPizzaStore::~NyPizzaStore()
{
}

Pizza *NyPizzaStore::createPizza(PizzaType type) const
{
    switch (type) {
    case CheeseType:
        return new NyStyleCheesePizza;
        // fall down
    case VeggieType:
    case ClamType:
    case PepperoniType:
    default:
        return nullptr;
    }
}
