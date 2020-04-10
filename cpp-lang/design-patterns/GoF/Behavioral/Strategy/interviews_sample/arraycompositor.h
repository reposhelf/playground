#ifndef ARRAYCOMPOSITOR_H
#define ARRAYCOMPOSITOR_H

#include "compositor.h"

class ArrayCompositor : public Compositor
{
public:
    explicit ArrayCompositor(int interval);
    int compose(Coord natural[],
                Coord stretch[],
                Coord shrink[],
                int componentCount,
                int lineWidth,
                int breaks[]);
private:
    int _interval;
};

#endif // ARRAYCOMPOSITOR_H
