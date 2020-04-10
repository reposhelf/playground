#include "view.h"

#include <iostream>

void View::display()
{
    setFocus();
    doDisplay();
    resetFocus();
}

void View::doDisplay()
{
    std::cout << __FILE__ << ": " << __FUNCTION__ << std::endl;
}

void View::setFocus()
{
    // Empty
}

void View::resetFocus()
{
    // Empty
}
