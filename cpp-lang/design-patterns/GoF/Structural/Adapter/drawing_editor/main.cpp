#include <memory>

#include "text_shape_class_adapter.h"
#include "text_shape_object_adapter.h"
#include "text_view.h"

int main() {
    TextShapeClassAdapter text_shape_class_adapter;

    auto text_view = std::make_unique<TextView>();
    TextShapeObjectAdapter text_shape_object_adapter(std::move(text_view));

    return 0;
}
