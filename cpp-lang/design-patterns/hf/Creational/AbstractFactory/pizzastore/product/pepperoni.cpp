#include "pepperoni.h"

#include <iostream>

// Pepperoni
Pepperoni::Pepperoni()
{
}

Pepperoni::~Pepperoni()
{
}

// Sliced Pepperoni
SlicedPepperoni::SlicedPepperoni()
    : Pepperoni()
{
    std::cout << "Prepared Sliced Pepperoni" << std::endl;
}

SlicedPepperoni::~SlicedPepperoni()
{
}
