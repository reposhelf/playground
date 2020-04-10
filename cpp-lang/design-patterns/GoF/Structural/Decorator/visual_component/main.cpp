#include <memory>

#include "border_decorator.h"
#include "scroll_decorator.h"
#include "text_view.h"

int main()
{
    auto text_view = std::make_shared<TextView>();
    auto scroll_decorator = std::make_shared<ScrollDecorator>(text_view);
    auto border_decorator = std::make_shared<BorderDecorator>(scroll_decorator, 1);

    border_decorator->draw();

    return 0;
}
