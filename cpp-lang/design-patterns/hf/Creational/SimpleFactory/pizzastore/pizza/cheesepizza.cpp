#include "cheesepizza.h"

#include <iostream>
using std::cout;
using std::endl;

CheesePizza::CheesePizza()
    : Pizza()
{
}

CheesePizza::~CheesePizza()
{
}

void CheesePizza::prepare()
{
    cout << "CheesePizza: prepare" << endl;
}

void CheesePizza::bake()
{
    cout << "CheesePizza: bake" << endl;
}

void CheesePizza::cut()
{
    cout << "CheesePizza: cut" << endl;
}

void CheesePizza::box()
{
    cout << "CheesePizza: box" << endl;
}
