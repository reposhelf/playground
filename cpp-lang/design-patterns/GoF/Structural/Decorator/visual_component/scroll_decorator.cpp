#include "scroll_decorator.h"

#include <iostream>
#include <typeinfo>

ScrollDecorator::ScrollDecorator(std::shared_ptr<VisualComponent> component)
    : Decorator(component)
{
    // Empty
}

ScrollDecorator::~ScrollDecorator()
{
    // Empty
}

void ScrollDecorator::draw()
{
    Decorator::draw();
    scroll_to();
}

void ScrollDecorator::scroll_to()
{
    std::cout << typeid(this).name() << "::" << __func__ << '\n';
}
