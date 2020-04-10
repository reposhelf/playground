#include "mallardduck.h"
#include "wildturkey.h"
#include "turkeyadapter.h"
#include "duckadapter.h"

#include <iostream>
using namespace std;

void testDuck(Duck *duck)
{
    duck->quack();
    duck->fly();
}

void testTurkey(Turkey *turkey)
{
    turkey->gobble();
    turkey->fly();
}

int main()
{
    auto duck = new MallardDuck;
    cout << "\nDuck says..." << endl;
    testDuck(duck);

    auto turkey = new WildTurkey;
    cout << "\nTurkey says..." << endl;
    testTurkey(turkey);

    auto turkeyAdapter = new TurkeyAdapter(turkey);
    cout << "\nTurkey adapter says..." << endl;
    testDuck(turkeyAdapter);

    auto duckAdapter = new DuckAdapter(duck);
    cout << "\nDuck adapter says..." << endl;
    testTurkey(duckAdapter);

    return 0;
}
