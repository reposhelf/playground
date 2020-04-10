#include <cstdlib>

#include "item.h"
//#include "exch.h"
#include "array.h"

int main(int argc, char **argv)
{
    // TODO: check argv size!

    int count = std::atoi(argv[1]);
    // may mean that if not zero then fill
    // by random values, otherwise scan
    const int canFillRandomly = std::atoi(argv[2]);

    Item *a = new Item[count];

    if (canFillRandomly) {
        rand(a, count);
    } else {
        scan(a, count);
    }

    sort(a, 0, count - 1);
    show(a, 0, count - 1);

    delete[] a;

    return 0;
}
