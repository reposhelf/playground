#include "text_shape_object_adapter.h"

TextShapeObjectAdapter::TextShapeObjectAdapter(std::unique_ptr<TextView> text_view)
    : text_view_(std::move(text_view)) {
    // Empty
}

TextShapeObjectAdapter::~TextShapeObjectAdapter() {
    // Empty
}

void TextShapeObjectAdapter::bounding_box(Point &bottom_left, Point &top_right) const {
    Coord bottom;
    Coord left;
    Coord width;
    Coord height;

    text_view_->get_origin(bottom, left);
    text_view_->get_extent(width, height);

    bottom_left = Point(bottom.value, left.value);
    top_right = Point(bottom.value + height.value, left.value + width.value);
}

std::shared_ptr<Manipulator> TextShapeObjectAdapter::create_manipulator() const {
    return std::make_shared<Manipulator>(const_cast<TextShapeObjectAdapter*>(this));
}

bool TextShapeObjectAdapter::is_empty() const {
    return text_view_->is_empty();
}
