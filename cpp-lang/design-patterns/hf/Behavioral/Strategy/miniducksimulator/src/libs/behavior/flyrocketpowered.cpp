#include "flyrocketpowered.h"

#include <iostream>

FlyRocketPowered::FlyRocketPowered()
    : FlyBehavior()
{

}

FlyRocketPowered::~FlyRocketPowered()
{

}

void FlyRocketPowered::fly() const
{
    std::cout << "I'm flying with a rocket!" << std::endl;
}
