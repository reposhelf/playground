#include "arraycompositor.h"

#include <iostream>

ArrayCompositor::ArrayCompositor(int interval)
    : _interval(interval)
{
    // nothing to do
}

int ArrayCompositor::compose(Coord* /*natural[]*/,
                             Coord* /*stretch[]*/,
                             Coord* /*shrink[]*/,
                             int /*componentCount*/,
                             int /*lineWidth*/,
                             int* /*breaks[]*/)
{
    std::cout << __FILE__ << ": " << __FUNCTION__ << std::endl;
    return 0;
}
