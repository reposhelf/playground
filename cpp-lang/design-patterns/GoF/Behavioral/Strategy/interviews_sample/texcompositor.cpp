#include "texcompositor.h"

#include <iostream>

TeXCompositor::TeXCompositor()
    : Compositor()
{
    // nothing to do
}

int TeXCompositor::compose(Coord* /*natural[]*/,
                           Coord* /*stretch[]*/,
                           Coord* /*shrink[]*/,
                           int /*componentCount*/,
                           int /*lineWidth*/,
                           int* /*breaks[]*/)
{
    std::cout << __FILE__ << ": " << __FUNCTION__ << std::endl;
    return 0;
}
