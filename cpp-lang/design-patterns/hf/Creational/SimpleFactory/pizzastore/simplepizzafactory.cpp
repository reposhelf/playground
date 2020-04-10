#include "simplepizzafactory.h"
#include "cheesepizza.h"
#include "veggiepizza.h"
#include "clampizza.h"
#include "pepperonipizza.h"

SimplePizzaFactory::SimplePizzaFactory()
{
}

Pizza *SimplePizzaFactory::createPizza(PizzaType type) const
{
    switch (type) {
    case Cheese: return new CheesePizza;
    case Veggie: return new VeggiePizza;
    case Clam: return new ClamPizza;
    case Pepperoni: return new PepperoniPizza;
    default: return nullptr;
    }
}
