#include "view.h"
#include "window.h"

int main()
{
    auto view = std::make_shared<View>();
    Window window(view);
    window.drawRect(std::make_pair<int, int>(0, 0),
                    std::make_pair<int, int>(640, 480));
    return 0;
}
