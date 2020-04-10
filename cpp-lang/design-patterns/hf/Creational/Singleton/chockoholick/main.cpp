#include "chocolateboiler.h"

int main()
{
    ChocolateBoiler::fill();
    ChocolateBoiler::fill();

    ChocolateBoiler::boil();
    ChocolateBoiler::boil();

    ChocolateBoiler::drain();
    ChocolateBoiler::drain();

    //======================
    ChocolateBoiler::drain();
    ChocolateBoiler::boil();

    ChocolateBoiler::fill();
    ChocolateBoiler::drain();

    ChocolateBoiler::boil();
    ChocolateBoiler::drain();

    return 0;
}
