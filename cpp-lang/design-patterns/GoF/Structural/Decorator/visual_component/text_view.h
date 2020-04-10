#ifndef TEXT_VIEW_H
#define TEXT_VIEW_H

#include "visual_component.h"

class TextView : public VisualComponent
{
public:
    TextView();
    ~TextView() override;

    void draw() override;
    void resize() override;
};

#endif // TEXT_VIEW_H
