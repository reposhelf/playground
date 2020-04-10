#include "composition.h"
#include "arraycompositor.h"
#include "simplecompositor.h"
#include "texcompositor.h"

int main()
{
    auto simpleCompositor = new SimpleCompositor();
    auto texCompositor = new TeXCompositor();
    auto arrayCompositor = new ArrayCompositor(100);

    Composition composition(simpleCompositor);
    composition.repair();

    composition.setCompositor(texCompositor);
    composition.repair();

    composition.setCompositor(arrayCompositor);
    composition.repair();

    delete arrayCompositor;
    delete texCompositor;
    delete simpleCompositor;

    return 0;
}
