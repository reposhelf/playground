#ifndef DECORATOR_H
#define DECORATOR_H

#include "visual_component.h"

#include <memory>

class Decorator : public VisualComponent
{
public:
    Decorator(std::shared_ptr<VisualComponent> component);
    ~Decorator() override;

    void draw() override;
    void resize() override;

private:
    std::shared_ptr<VisualComponent> component_;
};

#endif // DECORATOR_H
