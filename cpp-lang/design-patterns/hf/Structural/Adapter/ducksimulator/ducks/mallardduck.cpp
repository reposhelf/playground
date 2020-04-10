#include "mallardduck.h"

#include <iostream>
using namespace std;

MallardDuck::MallardDuck()
    : Duck()
{
}

MallardDuck::~MallardDuck()
{
}

void MallardDuck::quack() const
{
    cout << "Quack" << endl;
}

void MallardDuck::fly() const
{
    cout << "I can fly" << endl;
}
