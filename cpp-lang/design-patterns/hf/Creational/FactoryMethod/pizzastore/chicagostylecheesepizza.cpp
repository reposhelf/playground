#include "chicagostylecheesepizza.h"

#include <iostream>
using std::cout;
using std::endl;

ChicagoStyleCheesePizza::ChicagoStyleCheesePizza()
    : Pizza()
{
    initialize();
}

ChicagoStyleCheesePizza::~ChicagoStyleCheesePizza()
{
}

void ChicagoStyleCheesePizza::cut() const
{
    cout << "Cutting the pizza into square slices" << endl;
}

void ChicagoStyleCheesePizza::initialize()
{
    setName("Chicago Style Deep Dish Cheese Pizza");
    setDought("Extra Thick Crust Pizza");
    setSauce("Plum Tomato Sauce");
    addTopping("Shredder Mozzarella Cheese");
}
