#ifndef PIZZAINGREDIENTFACTORY_H
#define PIZZAINGREDIENTFACTORY_H

#include <list>

class Dough;
class Sauce;
class Cheese;
class Pepperoni;
class Clam;
class Veggie;
class PizzaIngredientFactory
{
public:
    PizzaIngredientFactory();
    virtual ~PizzaIngredientFactory();

    virtual Dough *createDough() const = 0;
    virtual Sauce *createSauce() const = 0;
    virtual Cheese *createCheese() const = 0;
    virtual Pepperoni *createPepperoni() const = 0;
    virtual Clam *createClam() const = 0;
    virtual std::list<Veggie *> createVeggies() const = 0;
};

class NyPizzaIngredientFactory : public PizzaIngredientFactory
{
public:
    NyPizzaIngredientFactory();
    ~NyPizzaIngredientFactory();

    Dough *createDough() const;
    Sauce *createSauce() const;
    Cheese *createCheese() const;
    Pepperoni *createPepperoni() const;
    Clam *createClam() const;
    std::list<Veggie *> createVeggies() const;
};

class ChicagoPizzaIngredientFactory : public PizzaIngredientFactory
{
public:
    ChicagoPizzaIngredientFactory();
    ~ChicagoPizzaIngredientFactory();

    Dough *createDough() const;
    Sauce *createSauce() const;
    Cheese *createCheese() const;
    Pepperoni *createPepperoni() const;
    Clam *createClam() const;
    std::list<Veggie *> createVeggies() const;
};

#endif // PIZZAINGREDIENTFACTORY_H
