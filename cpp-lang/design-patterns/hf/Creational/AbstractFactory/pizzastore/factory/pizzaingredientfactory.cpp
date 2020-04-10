#include "pizzaingredientfactory.h"
#include "dough.h"
#include "sauce.h"
#include "cheese.h"
#include "pepperoni.h"
#include "clam.h"
#include "veggie.h"

// Pizza Ingredient Factory
PizzaIngredientFactory::PizzaIngredientFactory()
{
}

PizzaIngredientFactory::~PizzaIngredientFactory()
{
}

// New York Pizza Ingredient Factory
NyPizzaIngredientFactory::NyPizzaIngredientFactory()
    : PizzaIngredientFactory()
{
}

NyPizzaIngredientFactory::~NyPizzaIngredientFactory()
{
}

Dough *NyPizzaIngredientFactory::createDough() const
{
    return new ThinCrustDough;
}

Sauce *NyPizzaIngredientFactory::createSauce() const
{
    return new MarinaraSauce;
}

Cheese *NyPizzaIngredientFactory::createCheese() const
{
    return new ReggianoCheese;
}

Pepperoni *NyPizzaIngredientFactory::createPepperoni() const
{
    return new SlicedPepperoni;
}

Clam *NyPizzaIngredientFactory::createClam() const
{
    return new FreshClam;
}

std::list<Veggie *> NyPizzaIngredientFactory::createVeggies() const
{
    std::list<Veggie *> veggies;
    veggies.push_back(new Garlic);
    veggies.push_back(new Onion);
    veggies.push_back(new Mushroom);
    veggies.push_back(new RedPepper);

    return veggies;
}

// Chicago Pizza Ingredient Factory
ChicagoPizzaIngredientFactory::ChicagoPizzaIngredientFactory()
    : PizzaIngredientFactory()
{
}

ChicagoPizzaIngredientFactory::~ChicagoPizzaIngredientFactory()
{
}

Dough *ChicagoPizzaIngredientFactory::createDough() const
{
    return new ThickCrustDough;
}

Sauce *ChicagoPizzaIngredientFactory::createSauce() const
{
    return new PlumTomatoSauce;
}

Cheese *ChicagoPizzaIngredientFactory::createCheese() const
{
    return new MozzarellaCheese;
}

Pepperoni *ChicagoPizzaIngredientFactory::createPepperoni() const
{
    return new SlicedPepperoni;
}

Clam *ChicagoPizzaIngredientFactory::createClam() const
{
    return new FrozenClam;
}

std::list<Veggie *> ChicagoPizzaIngredientFactory::createVeggies() const
{
    std::list<Veggie *> veggies;
    veggies.push_back(new BlackOlives);
    veggies.push_back(new Spinach);
    veggies.push_back(new EggPlant);

    return veggies;
}
