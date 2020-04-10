#include "text_shape_class_adapter.h"

TextShapeClassAdapter::TextShapeClassAdapter()
    : Shape(), TextView() {
    // Empty
}

TextShapeClassAdapter::~TextShapeClassAdapter() {
    // Empty
}

void TextShapeClassAdapter::bounding_box(Point &bottom_left, Point &top_right) const {
    Coord bottom;
    Coord left;
    Coord width;
    Coord height;

    get_origin(bottom, left);
    get_extent(width, height);

    bottom_left = Point(bottom.value, left.value);
    top_right = Point(bottom.value + height.value, left.value + width.value);
}

std::shared_ptr<Manipulator> TextShapeClassAdapter::create_manipulator() const {
    return std::make_shared<Manipulator>(const_cast<TextShapeClassAdapter*>(this));
}

bool TextShapeClassAdapter::is_empty() const {
    return TextView::is_empty();
}
