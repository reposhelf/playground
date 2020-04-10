#ifndef SIMPLEPIZZAFACTORY_H
#define SIMPLEPIZZAFACTORY_H

class Pizza;
class SimplePizzaFactory
{
public:
    enum PizzaType {
        Cheese,
        Veggie,
        Clam,
        Pepperoni
    };

    SimplePizzaFactory();

    Pizza *createPizza(PizzaType) const;
};

#endif // SIMPLEPIZZAFACTORY_H
