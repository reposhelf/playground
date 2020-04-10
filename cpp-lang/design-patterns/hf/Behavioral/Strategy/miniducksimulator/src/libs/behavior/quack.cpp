#include "quack.h"

#include <iostream>

Quack::Quack()
    : QuackBehavior()
{

}

Quack::~Quack()
{

}

void Quack::quack() const
{
    std::cout << "Quack!" << std::endl;
}
