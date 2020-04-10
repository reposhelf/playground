#ifndef TEXT_SHAPE_CLASS_ADAPTER_H
#define TEXT_SHAPE_CLASS_ADAPTER_H

#include "shape.h"
#include "text_view.h"

class TextShapeClassAdapter : public Shape, private TextView {
public:
    TextShapeClassAdapter();
    ~TextShapeClassAdapter();

    void bounding_box(Point &bottom_left, Point &top_right) const override;
    std::shared_ptr<Manipulator> create_manipulator() const override;
    bool is_empty() const override;
};

#endif
