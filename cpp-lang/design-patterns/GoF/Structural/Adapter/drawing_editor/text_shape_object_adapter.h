#ifndef TEXT_SHAPE_OBJECT_ADAPTER_H
#define TEXT_SHAPE_OBJECT_ADAPTER_H

#include <memory>

#include "shape.h"
#include "text_view.h"

class TextShapeObjectAdapter : public Shape {
public:
    explicit TextShapeObjectAdapter(std::unique_ptr<TextView>);
    ~TextShapeObjectAdapter();

    void bounding_box(Point &bottom_left, Point &top_right) const override;
    std::shared_ptr<Manipulator> create_manipulator() const override;
    bool is_empty() const;

private:
    std::unique_ptr<TextView> text_view_;
};

#endif
