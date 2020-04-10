#include "chicagopizzastore.h"
#include "chicagostylecheesepizza.h"

ChicagoPizzaStore::ChicagoPizzaStore()
    : PizzaStore()
{
}

ChicagoPizzaStore::~ChicagoPizzaStore()
{
}

Pizza *ChicagoPizzaStore::createPizza(PizzaType type) const
{
    switch (type) {
    case CheeseType:
        return new ChicagoStyleCheesePizza;
        // fall down
    case VeggieType:
    case ClamType:
    case PepperoniType:
    default:
        return nullptr;
    }
}
