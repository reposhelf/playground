#ifndef SCROLL_DECORATOR_H
#define SCROLL_DECORATOR_H

#include <memory>

#include "decorator.h"

class ScrollDecorator : public Decorator
{
public:
    ScrollDecorator(std::shared_ptr<VisualComponent> component);
    ~ScrollDecorator() override;

    void draw() override;

private:
    void scroll_to();
};

#endif // SCROLL_DECORATOR_H
