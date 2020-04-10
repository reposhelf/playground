#include "pizzastore.h"
#include "simplepizzafactory.h"
#include "pizza.h"

int main()
{
    SimplePizzaFactory factory;
    PizzaStore pizzaStore(&factory);
    Pizza *pizza = pizzaStore.orderPizza(SimplePizzaFactory::Pepperoni);

    if (pizza)
        delete pizza;

    return 0;
}
