#include "composition.h"
#include "compositor.h"

Composition::Composition(Compositor *compositor)
    : _compositor(compositor),
      _components(nullptr),
      _componentCount(0),
      _lineWidth(0),
      _lineBreaks(nullptr),
      _lineCount(0)
{
    // nothing to do
}

void Composition::repair()
{
    // just for example, details omitted
    Coord* natural = nullptr;
    Coord* stretchability = nullptr;
    Coord* shrinkability = nullptr;
    int componentCount = 0;
    int* breaks = nullptr;

    int breakCount = 0;
    if (_compositor) {
        breakCount = _compositor->compose(natural,
                                          stretchability,
                                          shrinkability,
                                          componentCount,
                                          _lineWidth,
                                          breaks);
    }
    // just to calm the compiler
    breakCount = breakCount;
}

void Composition::setCompositor(Compositor *compositor)
{
    _compositor = compositor;
}

Compositor *Composition::getCompositor() const
{
    return _compositor;
}
