#include "sauce.h"

#include <iostream>

// Sauce
Sauce::Sauce()
{
}

Sauce::~Sauce()
{
}

// Marinara Sauce
MarinaraSauce::MarinaraSauce()
    : Sauce()
{
    std::cout << "Prepared Marinara Sauce" << std::endl;
}

MarinaraSauce::~MarinaraSauce()
{
}

// Plum Tomato Sauce
PlumTomatoSauce::PlumTomatoSauce()
    : Sauce()
{
    std::cout << "Prepared Plum Tomato Sauce" << std::endl;
}

PlumTomatoSauce::~PlumTomatoSauce()
{
}
