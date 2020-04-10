#include "veggiepizza.h"

#include <iostream>
using std::cout;
using std::endl;

VeggiePizza::VeggiePizza()
    : Pizza()
{
}

VeggiePizza::~VeggiePizza()
{
}

void VeggiePizza::prepare()
{
    cout << "VeggiePizza: prepare" << endl;
}

void VeggiePizza::bake()
{
    cout << "VeggiePizza: bake" << endl;
}

void VeggiePizza::cut()
{
    cout << "VeggiePizza: cut" << endl;
}

void VeggiePizza::box()
{
    cout << "VeggiePizza: box" << endl;
}
