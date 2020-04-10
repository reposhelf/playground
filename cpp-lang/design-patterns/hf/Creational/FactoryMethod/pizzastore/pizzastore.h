#ifndef PIZZASTORE_H
#define PIZZASTORE_H

class Pizza;
class PizzaStore
{
public:
    enum PizzaType {
        CheeseType,
        VeggieType,
        ClamType,
        PepperoniType
    };

    PizzaStore();
    virtual ~PizzaStore();

    virtual Pizza *orderPizza(PizzaType) const final;

protected:
    virtual Pizza *createPizza(PizzaType) const = 0;
};

#endif // PIZZASTORE_H
