#include "pizzastore.h"
#include "pizza.h"
#include "pizzaingredientfactory.h"

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

// New York Pizza Store
NyPizzaStore::NyPizzaStore()
    : PizzaStore()
{
}

NyPizzaStore::~NyPizzaStore()
{
}

Pizza *NyPizzaStore::createPizza(PizzaType type) const
{
    PizzaIngredientFactory *factory = new NyPizzaIngredientFactory;
    Pizza *pizza = nullptr;
    switch (type) {
    case Cheese:
        pizza = new CheesePizza(factory);
        pizza->setName("New York Style Cheese Pizza");
        break;
    case Veggie:
        pizza = new VeggiePizza(factory);
        pizza->setName("New York Style Veggie Pizza");
        break;
    case Clam:
        pizza = new ClamPizza(factory);
        pizza->setName("New York Style Clam Pizza");
        break;
    case Pepperoni:
        pizza = new PepperoniPizza(factory);
        pizza->setName("New York Style Pepperoni Pizza");
        break;
    default:
        break;
    }
    return pizza;
}

// Chicago Pizza Store
ChicagoPizzaStore::ChicagoPizzaStore()
    : PizzaStore()
{
}

ChicagoPizzaStore::~ChicagoPizzaStore()
{
}

Pizza *ChicagoPizzaStore::createPizza(PizzaStore::PizzaType type) const
{
    PizzaIngredientFactory *factory = new ChicagoPizzaIngredientFactory;
    Pizza *pizza = nullptr;
    switch (type) {
    case Cheese:
        pizza = new CheesePizza(factory);
        pizza->setName("Chicago Style Cheese Pizza");
        break;
    case Veggie:
        pizza = new VeggiePizza(factory);
        pizza->setName("Chicago Style Veggie Pizza");
        break;
    case Clam:
        pizza = new ClamPizza(factory);
        pizza->setName("Chicago Style Clam Pizza");
        break;
    case Pepperoni:
        pizza = new PepperoniPizza(factory);
        pizza->setName("Chicago Style Pepperoni Pizza");
        break;
    default:
        break;
    }
    return pizza;
}
