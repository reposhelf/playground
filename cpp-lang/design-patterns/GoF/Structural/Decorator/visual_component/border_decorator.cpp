#include "border_decorator.h"

#include <iostream>
#include <typeinfo>

BorderDecorator::BorderDecorator(std::shared_ptr<VisualComponent> component, int width)
    : Decorator(component),
      width_(width)
{
    // Empty
}

BorderDecorator::~BorderDecorator()
{
    // Empty
}

void BorderDecorator::draw()
{
    Decorator::draw();
    draw_border(width_);
}

void BorderDecorator::draw_border(int width)
{
    std::cout << typeid(this).name() << "::" << __func__ << '\n';
}
