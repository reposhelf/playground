#include "dough.h"

#include <iostream>

// Dough
Dough::Dough()
{
}

Dough::~Dough()
{
}

// Thick Crust Dough
ThickCrustDough::ThickCrustDough()
    : Dough()
{
    std::cout << "Prepared Thick Crust Dough" << std::endl;
}

ThickCrustDough::~ThickCrustDough()
{
}

// Thin Crust Dough
ThinCrustDough::ThinCrustDough()
    : Dough()
{
    std::cout << "Prepared Thin Crust Dough" << std::endl;
}

ThinCrustDough::~ThinCrustDough()
{
}


