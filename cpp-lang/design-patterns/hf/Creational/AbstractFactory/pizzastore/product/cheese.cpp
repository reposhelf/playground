#include "cheese.h"

#include <iostream>

// Cheese
Cheese::Cheese()
{
}

Cheese::~Cheese()
{
}

// Mozzarella Cheese
MozzarellaCheese::MozzarellaCheese()
    : Cheese()
{
    std::cout << "Prepared Mozzarella Cheese" << std::endl;
}

MozzarellaCheese::~MozzarellaCheese()
{
}

// Reggiano Cheese
ReggianoCheese::ReggianoCheese()
    : Cheese()
{
    std::cout << "Prepared Reggiano Cheese" << std::endl;
}

ReggianoCheese::~ReggianoCheese()
{
}


