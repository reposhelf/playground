#include "view.h"
#include "myview.h"

int main()
{
    auto view = new View;
    view->display();
    delete view;

    view = new MyView;
    view->display();
    delete view;

    return 0;
}
