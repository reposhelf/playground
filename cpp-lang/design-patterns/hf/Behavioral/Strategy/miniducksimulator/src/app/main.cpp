#include "mallardduck.h"
#include "modelduck.h"
#include "flyrocketpowered.h"

using namespace std;

int main()
{
    Duck *mallardDuck = new MallardDuck;
    mallardDuck->quack();
    mallardDuck->fly();
    delete mallardDuck;

    Duck *modelDuck = new ModelDuck;
    modelDuck->fly();
    modelDuck->setFlyBehavior(new FlyRocketPowered);
    modelDuck->fly();
    delete modelDuck;

    return 0;
}
