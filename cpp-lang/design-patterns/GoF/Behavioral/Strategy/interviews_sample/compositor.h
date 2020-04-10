#ifndef COMPOSITOR_H
#define COMPOSITOR_H

struct Coord
{
    int x = 0;
    int y = 0;
};

class Compositor
{
public:
    virtual int compose(Coord natural[],
                        Coord stretch[],
                        Coord shrink[],
                        int componentCount,
                        int lineWidth,
                        int breaks[]) = 0;
protected:
    Compositor() = default;
    virtual ~Compositor() = default;
};

#endif // COMPOSITOR_H
