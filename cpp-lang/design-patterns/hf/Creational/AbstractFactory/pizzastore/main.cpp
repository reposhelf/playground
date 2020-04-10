#include "pizzastore.h"
#include "pizza.h"

int main()
{
    PizzaStore *nyPizzaStore = new NyPizzaStore;
    Pizza *nyStyleCheesePizza = nyPizzaStore->orderPizza(PizzaStore::Cheese);
    Pizza *nyStypeVeggiePizza = nyPizzaStore->orderPizza(PizzaStore::Veggie);
    Pizza *nyStyleClamPizza = nyPizzaStore->orderPizza(PizzaStore::Clam);
    Pizza *nyStylePepperoniPizza = nyPizzaStore->orderPizza(PizzaStore::Pepperoni);

    PizzaStore *chicagoPizzaStore = new ChicagoPizzaStore;
    Pizza *chicagoStyleCheesePizza = chicagoPizzaStore->orderPizza(PizzaStore::Cheese);
    Pizza *chicagoStypeVeggiePizza = chicagoPizzaStore->orderPizza(PizzaStore::Veggie);
    Pizza *chicagoStyleClamPizza = chicagoPizzaStore->orderPizza(PizzaStore::Clam);
    Pizza *chicagoStylePepperoniPizza = chicagoPizzaStore->orderPizza(PizzaStore::Pepperoni);


    delete nyStyleCheesePizza;
    delete nyStypeVeggiePizza;
    delete nyStyleClamPizza;
    delete nyStylePepperoniPizza;

    delete nyPizzaStore;

    delete chicagoStyleCheesePizza;
    delete chicagoStypeVeggiePizza;
    delete chicagoStyleClamPizza;
    delete chicagoStylePepperoniPizza;

    delete chicagoPizzaStore;

    return 0;
}
