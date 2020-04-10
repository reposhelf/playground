#include "espresso.h"
#include "darkroast.h"
#include "houseblend.h"
#include "mocha.h"
#include "whip.h"
#include "soy.h"

#include <iostream>
using namespace std;

int main()
{
    Beverage *beverage = new Espresso;
    cout << beverage->description()
         << " $" << beverage->cost()
         << endl;

    Beverage *beverage2 = new DarkRoast;
    beverage2 = new Mocha(beverage2);
    beverage2 = new Mocha(beverage2);
    beverage2 = new Whip(beverage2);
    cout << beverage2->description()
         << " $" << beverage2->cost()
         << endl;

    Beverage *beverage3 = new HouseBlend;
    beverage3 = new Soy(beverage3);
    beverage3 = new Mocha(beverage3);
    beverage3 = new Whip(beverage3);
    cout << beverage3->description()
         << " $" << beverage3->cost()
         << endl;

    delete beverage;
    delete beverage2;
    delete beverage3;

    return 0;
}
