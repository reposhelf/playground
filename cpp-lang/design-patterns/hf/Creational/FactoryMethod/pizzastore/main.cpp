#include "nypizzastore.h"
#include "chicagopizzastore.h"
#include "pizza.h"

int main()
{
    PizzaStore *nyPizzaStore = new NyPizzaStore;
    Pizza *nyPizza = nyPizzaStore->orderPizza(PizzaStore::CheeseType);

    PizzaStore *chicagoPizzaStore = new ChicagoPizzaStore;
    Pizza *chicagoPizza = chicagoPizzaStore->orderPizza(PizzaStore::CheeseType);

    if (nyPizza)
        delete nyPizza;
    if (chicagoPizza)
        delete chicagoPizza;

    delete nyPizzaStore;
    delete chicagoPizzaStore;

    return 0;
}
