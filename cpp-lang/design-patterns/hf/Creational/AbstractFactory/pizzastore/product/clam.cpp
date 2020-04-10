#include "clam.h"

#include <iostream>

// Clam
Clam::Clam()
{
}

Clam::~Clam()
{
}

// Fresh Clam
FreshClam::FreshClam()
    : Clam()
{
    std::cout << "Prepared Fresh Clam" << std::endl;
}

FreshClam::~FreshClam()
{
}

// Frozen Clam
FrozenClam::FrozenClam()
    : Clam()
{
    std::cout << "Prepared Frozen Clam" << std::endl;
}

FrozenClam::~FrozenClam()
{
}

