#include "tea.h"

#include <iostream>
#include <algorithm>

Tea::Tea()
    : CaffeineBeverage()
{
}

void Tea::brew() const
{
    std::cout << "Steeping the tea" << std::endl;
}

void Tea::addCondiments() const
{
    std::cout << "Adding Lemon" << std::endl;
}

bool Tea::customerWantsCondiments() const
{
    if (askAboutCondiments() == "y")
        return true;
    return false;
}

std::string Tea::askAboutCondiments() const
{
    std::cout << "Would you like lemon with your tea (y/n)? ";
    std::string result;
    std::cin >> result;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}
