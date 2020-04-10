#include "pepperonipizza.h"

#include <iostream>
using std::cout;
using std::endl;

PepperoniPizza::PepperoniPizza()
    : Pizza()
{
}

PepperoniPizza::~PepperoniPizza()
{
}

void PepperoniPizza::prepare()
{
    cout << "PepperoniPizza: prepare" << endl;
}

void PepperoniPizza::bake()
{
    cout << "PepperoniPizza: bake" << endl;
}

void PepperoniPizza::cut()
{
    cout << "PepperoniPizza: cut" << endl;
}

void PepperoniPizza::box()
{
    cout << "PepperoniPizza: box" << endl;
}
