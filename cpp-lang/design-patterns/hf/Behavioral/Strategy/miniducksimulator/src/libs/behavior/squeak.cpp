#include "squeak.h"

#include <iostream>

Squeak::Squeak()
    : QuackBehavior()
{

}

Squeak::~Squeak()
{

}

void Squeak::quack() const
{
    std::cout << "Quack!" << std::endl;
}
