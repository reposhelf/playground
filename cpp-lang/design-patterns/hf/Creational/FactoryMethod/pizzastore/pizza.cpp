#include "pizza.h"

#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::list;

Pizza::Pizza()
    : _name(),
      _dought(),
      _sauce(),
      _toppings()
{
}

Pizza::~Pizza()
{
}

void Pizza::setName(const string &n)
{
    _name = n;
}

void Pizza::setDought(const string &d)
{
    _dought = d;
}

void Pizza::setSauce(const string &s)
{
    _sauce = s;
}

void Pizza::setToppings(const list<string> &t)
{
    _toppings = t;
}

void Pizza::addTopping(const string &t)
{
    _toppings.push_back(t);
}

void Pizza::prepare() const
{
    cout << "Preparing " << _name << endl;
    cout << "Tossing " << _dought << endl;
    cout << "Adding " << _sauce << endl;
    cout << "Adding toppings: " << endl;
    for (const string &t : _toppings)
        cout << "    " << t << endl;
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
