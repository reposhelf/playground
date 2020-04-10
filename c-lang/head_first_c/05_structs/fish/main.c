#include "fish.h"

int main()
{
    struct fish snappy = {"Nibbler", "piranha", 69, 4,
                         {{"meat", 0.09},
                          {"bath in the hot tub", 7.5}}};
    catalog(snappy);
    label(snappy);
    return 0;
}