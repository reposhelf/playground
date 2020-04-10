#include "flywithwings.h"

#include <iostream>

FlyWithWings::FlyWithWings()
    : FlyBehavior()
{

}

FlyWithWings::~FlyWithWings()
{

}

void FlyWithWings::fly() const
{
    std::cout << "I'm flying!" << std::endl;
}
