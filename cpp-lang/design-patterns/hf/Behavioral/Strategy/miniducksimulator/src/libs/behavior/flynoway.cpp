#include "flynoway.h"

#include <iostream>

FlyNoWay::FlyNoWay()
    : FlyBehavior()
{

}

FlyNoWay::~FlyNoWay()
{

}

void FlyNoWay::fly() const
{
    std::cout << "I can't fly." << std::endl;
}
