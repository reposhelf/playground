#ifndef COMPOSITION_H
#define COMPOSITION_H

class Compositor;
class Component; // details omitted
class Composition
{
public:
    explicit Composition(Compositor *compositor);
    void repair();
    void setCompositor(Compositor *compositor);
    Compositor *getCompositor() const;
private:
    Compositor* _compositor;
    Component* _components;
    int _componentCount;
    int _lineWidth;
    int* _lineBreaks;
    int _lineCount;
};

#endif // COMPOSITION_H
