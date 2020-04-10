#include "malloc2d.h"

namespace IntMalloc2D {

int **malloc2d(int rowCount, int columnCount)
{
    int **a = new int*[rowCount];
    for (int i = 0; i < rowCount; ++i)
        a[i] = new int[columnCount];
    return a;
}

};