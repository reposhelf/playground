#include "pizza.h"
#include "dough.h"
#include "sauce.h"
#include "cheese.h"
#include "pepperoni.h"
#include "clam.h"
#include "veggie.h"
#include "pizzaingredientfactory.h"

#include <iostream>
using namespace std;

// Pizza
Pizza::Pizza(PizzaIngredientFactory *ingredientFctory)
    : _ingredientFactory(ingredientFctory),
      _name(),
      _dough(nullptr),
      _sauce(nullptr),
      _cheese(nullptr),
      _pepperoni(nullptr),
      _clam(nullptr),
      _veggies()
{
}

Pizza::~Pizza()
{
    delete _dough;
    delete _sauce;
    delete _cheese;
    delete _pepperoni;
    delete _clam;

    for (Veggie *v : _veggies)
        delete v;

    _veggies.clear();

    delete _ingredientFactory;
}

void Pizza::setName(const string &name)
{
    _name = name;
}

void Pizza::setDough(Dough *dough)
{
    _dough = dough;
}

void Pizza::setSauce(Sauce *sauce)
{
    _sauce = sauce;
}

void Pizza::setCheese(Cheese *cheese)
{
    _cheese = cheese;
}

void Pizza::setPepperoni(Pepperoni *pepperoni)
{
    _pepperoni = pepperoni;
}

void Pizza::setClam(Clam *clam)
{
    _clam = clam;
}

void Pizza::setVeggies(const std::list<Veggie *> &veggies)
{
    _veggies = veggies;
}

void Pizza::bake() const
{
    cout << "Bake for 25 minutes at 350" << endl;
}

void Pizza::cut() const
{
    cout << "Cutting the pizza into diagonal slices" << endl;
}

void Pizza::box() const
{
    cout << "Place pizza in official PizzaStore box" << endl << endl;
}

// Cheese Pizza
CheesePizza::CheesePizza(PizzaIngredientFactory *ingredientFactory)
    : Pizza(ingredientFactory)
{
}

CheesePizza::~CheesePizza()
{
}

void CheesePizza::prepare()
{
    cout << "Preparing " << name() << endl;
    setDough(_ingredientFactory->createDough());
    setSauce(_ingredientFactory->createSauce());
    setCheese(_ingredientFactory->createCheese());
}

// Clam Pizza
ClamPizza::ClamPizza(PizzaIngredientFactory *ingredientFactory)
    : Pizza(ingredientFactory)
{
}

ClamPizza::~ClamPizza()
{
}

void ClamPizza::prepare()
{
    cout << "Preparing " << name() << endl;
    setDough(_ingredientFactory->createDough());
    setSauce(_ingredientFactory->createSauce());
    setCheese(_ingredientFactory->createCheese());
    setClam(_ingredientFactory->createClam());
}

// Veggie Pizza
VeggiePizza::VeggiePizza(PizzaIngredientFactory *ingredientFactory)
    : Pizza(ingredientFactory)
{
}

VeggiePizza::~VeggiePizza()
{
}

void VeggiePizza::prepare()
{
    cout << "Preparing " << name() << endl;
    setDough(_ingredientFactory->createDough());
    setSauce(_ingredientFactory->createSauce());
    setCheese(_ingredientFactory->createCheese());
    setVeggies(_ingredientFactory->createVeggies());
}

// Pepperoni Pizza
PepperoniPizza::PepperoniPizza(PizzaIngredientFactory *ingredientFactory)
    : Pizza(ingredientFactory)
{
}

PepperoniPizza::~PepperoniPizza()
{
}

void PepperoniPizza::prepare()
{
    cout << "Preparing " << name() << endl;
    setDough(_ingredientFactory->createDough());
    setSauce(_ingredientFactory->createSauce());
    setCheese(_ingredientFactory->createCheese());
    setPepperoni(_ingredientFactory->createPepperoni());
}
