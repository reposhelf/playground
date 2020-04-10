#include "caffeinebeverage.h"

#include <iostream>

CaffeineBeverage::CaffeineBeverage()
{
}

void CaffeineBeverage::prepareRecipe() const
{
    boilWater();
    brew();
    pourInCup();
    if (customerWantsCondiments())
        addCondiments();
}

void CaffeineBeverage::boilWater() const
{
    std::cout << "Boiling water" << std::endl;
}

void CaffeineBeverage::pourInCup() const
{
    std::cout << "Pouring into cup" << std::endl;
}

bool CaffeineBeverage::customerWantsCondiments() const
{
    return true;
}
