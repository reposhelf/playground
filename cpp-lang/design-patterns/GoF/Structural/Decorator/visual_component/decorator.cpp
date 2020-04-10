#include "decorator.h"

#include <iostream>

Decorator::Decorator(std::shared_ptr<VisualComponent> component)
    : VisualComponent(),
      component_(component)
{
    // Empty
}

Decorator::~Decorator()
{
    // Empty
}

void Decorator::draw()
{
    component_->draw();
}

void Decorator::resize()
{
    component_->resize();
}
