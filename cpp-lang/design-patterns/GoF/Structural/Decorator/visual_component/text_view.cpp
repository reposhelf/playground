#include "text_view.h"

#include <iostream>
#include <typeinfo>

TextView::TextView()
    : VisualComponent()
{
    // Empty
}

TextView::~TextView()
{
    // Empty
}

void TextView::draw()
{
    std::cout << typeid(this).name() << "::" << __func__ << '\n';
}

void TextView::resize()
{
    std::cout << typeid(this).name() << "::" << __func__ << '\n';
}
