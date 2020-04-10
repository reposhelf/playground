#include "nystylecheesepizza.h"

NyStyleCheesePizza::NyStyleCheesePizza()
    : Pizza()
{
    initialize();
}

NyStyleCheesePizza::~NyStyleCheesePizza()
{
}

void NyStyleCheesePizza::initialize()
{
    setName("NY Style Sauce and Cheese Pizza");
    setDought("Thin Crust Dought");
    setSauce("Marinara Sauce");
    addTopping("Grated Reggiano Cheese");
}
