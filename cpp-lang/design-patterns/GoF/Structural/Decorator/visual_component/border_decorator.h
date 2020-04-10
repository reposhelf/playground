#ifndef BORDER_DECORATOR_H
#define BORDER_DECORATOR_H

#include <memory>

#include "decorator.h"

class BorderDecorator : public Decorator
{
public:
    BorderDecorator(std::shared_ptr<VisualComponent> component, int width);
    ~BorderDecorator() override;

    void draw() override;

private:
    void draw_border(int width);

    int width_;
};

#endif // BORDER_DECORATOR_H
