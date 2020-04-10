#include "simplecompositor.h"

#include <iostream>

SimpleCompositor::SimpleCompositor()
    : Compositor()
{
    // nothing to do
}

int SimpleCompositor::compose(Coord* /*natural[]*/,
                              Coord* /*stretch[]*/,
                              Coord* /*shrink[]*/,
                              int /*componentCount*/,
                              int /*lineWidth*/,
                              int* /*breaks[]*/)
{
    std::cout << __FILE__ << ": " << __FUNCTION__ << std::endl;
    return 0;
}
