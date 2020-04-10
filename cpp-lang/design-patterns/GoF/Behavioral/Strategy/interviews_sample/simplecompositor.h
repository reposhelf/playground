#ifndef SIMPLECOMPOSITOR_H
#define SIMPLECOMPOSITOR_H

#include "compositor.h"

class SimpleCompositor : public Compositor
{
public:
    SimpleCompositor();
    int compose(Coord natural[],
                Coord stretch[],
                Coord shrink[],
                int componentCount,
                int lineWidth,
                int breaks[]);
};

#endif // SIMPLECOMPOSITOR_H
