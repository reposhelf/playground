#ifndef TEXCOMPOSITOR_H
#define TEXCOMPOSITOR_H

#include "compositor.h"

class TeXCompositor : public Compositor
{
public:
    TeXCompositor();
    int compose(Coord natural[],
                Coord stretch[],
                Coord shrink[],
                int componentCount,
                int lineWidth,
                int breaks[]);
};

#endif // TEXCOMPOSITOR_H
