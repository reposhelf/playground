#include "visual_component.h"

#include <iostream>
#include <typeinfo>

VisualComponent::VisualComponent()
{
    // Empty
}

VisualComponent::~VisualComponent()
{
    // Empty
}

void VisualComponent::draw()
{
    std::cout << typeid(this).name() << "::" << __func__ << '\n';
}

void VisualComponent::resize()
{
    std::cout << typeid(this).name() << "::" << __func__ << '\n';
}
