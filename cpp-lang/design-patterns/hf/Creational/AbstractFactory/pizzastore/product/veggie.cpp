#include "veggie.h"

#include <iostream>

// Veggie
Veggie::Veggie()
{
}

Veggie::~Veggie()
{
}

// Garlic
Garlic::Garlic()
    : Veggie()
{
    std::cout << "Prepared Garlic" << std::endl;
}

Garlic::~Garlic()
{
}

// Onion
Onion::Onion()
    : Veggie()
{
    std::cout << "Prepared Onion" << std::endl;
}

Onion::~Onion()
{
}

// Mushroom
Mushroom::Mushroom()
    : Veggie()
{
    std::cout << "Prepared Mushroom" << std::endl;
}

Mushroom::~Mushroom()
{
}

// RedPepper
RedPepper::RedPepper()
    : Veggie()
{
    std::cout << "Prepared Red Pepper" << std::endl;
}

RedPepper::~RedPepper()
{
}

// Black Olives
BlackOlives::BlackOlives()
    : Veggie()
{
    std::cout << "Prepared Black Olives" << std::endl;
}

BlackOlives::~BlackOlives()
{
}

// Spinach
Spinach::Spinach()
    : Veggie()
{
    std::cout << "Prepared Spinach" << std::endl;
}

Spinach::~Spinach()
{
}

// Egg Plant
EggPlant::EggPlant()
    : Veggie()
{
    std::cout << "Prepared Egg Plant" << std::endl;
}

EggPlant::~EggPlant()
{
}
