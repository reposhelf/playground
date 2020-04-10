#ifndef PIZZASTORE_H
#define PIZZASTORE_H

class Pizza;
class PizzaIngredientFactory;
class PizzaStore
{
public:
    enum PizzaType { Cheese, Veggie, Clam, Pepperoni };
    PizzaStore();
    virtual ~PizzaStore();

    Pizza *orderPizza(PizzaType type) const;

protected:
    virtual Pizza *createPizza(PizzaType type) const = 0;
};

class NyPizzaStore : public PizzaStore
{
public:
    NyPizzaStore();
    ~NyPizzaStore();

private:
    Pizza *createPizza(PizzaType type) const override;
};

class ChicagoPizzaStore : public PizzaStore
{
public:
    ChicagoPizzaStore();
    ~ChicagoPizzaStore();

private:
    Pizza *createPizza(PizzaType type) const override;
};

#endif // PIZZASTORE_H
