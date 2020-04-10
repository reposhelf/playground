#include "coffee.h"

#include <iostream>
#include <algorithm>

Coffee::Coffee()
    : CaffeineBeverage()
{
}

void Coffee::brew() const
{
    std::cout << "Dripping coffee through filter" << std::endl;
}

void Coffee::addCondiments() const
{
    std::cout << "Adding Sugar and Milk" << std::endl;
}

bool Coffee::customerWantsCondiments() const
{
    if (askAboutCondiments() == "y")
        return true;
    return false;
}

std::string Coffee::askAboutCondiments() const
{
    std::cout << "Would you like milk and sugar with your coffee (y/n)? ";
    std::string result;
    std::cin >> result;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}
