#ifndef VISUAL_COMPONENT_H
#define VISUAL_COMPONENT_H


class VisualComponent
{
public:
    VisualComponent();
    VisualComponent(const VisualComponent &) = delete;
    VisualComponent &operator=(const VisualComponent &) = delete;
    virtual ~VisualComponent();

    virtual void draw();
    virtual void resize();
};

#endif // VISUAL_COMPONENT_H
