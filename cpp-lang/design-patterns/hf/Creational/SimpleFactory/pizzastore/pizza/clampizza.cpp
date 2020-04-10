#include "clampizza.h"

#include <iostream>
using std::cout;
using std::endl;

ClamPizza::ClamPizza()
    : Pizza()
{
}

ClamPizza::~ClamPizza()
{
}

void ClamPizza::prepare()
{
    cout << "ClamPizza: prepare" << endl;
}

void ClamPizza::bake()
{
    cout << "ClamPizza: bake" << endl;
}

void ClamPizza::cut()
{
    cout << "ClamPizza: cut" << endl;
}

void ClamPizza::box()
{
    cout << "ClamPizza: box" << endl;
}
