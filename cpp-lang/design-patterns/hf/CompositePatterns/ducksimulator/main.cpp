#include "duckcall.h"
#include "mallardduck.h"
#include "redheadduck.h"
#include "rubberduck.h"
#include "gooseadapter.h"
#include "quackcounter.h"
#include "duckcountingfactory.h"
#include "flock.h"
#include "quackologist.h"

#include <iostream>

void simulate(const Quackable *duck) {
    if (duck)
        duck->quack();
}

void simulate(const AbstractDuckFactory *duckFactory) {
    Flock *flockOfDucks = new Flock;
    flockOfDucks->add(duckFactory->createDuckCall());
    flockOfDucks->add(duckFactory->createRedheadDuck());
    flockOfDucks->add(duckFactory->createRubberDuck());
    flockOfDucks->add(new GooseAdapter(new Goose));

    Flock *flockOfMallards = new Flock;
    flockOfMallards->add(duckFactory->createMallardDuck());
    flockOfMallards->add(duckFactory->createMallardDuck());
    flockOfMallards->add(duckFactory->createMallardDuck());
    flockOfMallards->add(duckFactory->createMallardDuck());

    flockOfDucks->add(flockOfMallards);

    Quackologist quackologist;
    flockOfDucks->registerObserver(&quackologist);

    simulate(flockOfDucks);

    std::cout << QuackCounter::numberOfQuacks() << " ";
    std::cout << "quacks were counted." << std::endl;

    delete flockOfDucks;
}

int main() {
    AbstractDuckFactory *duckFactory = new DuckCountingFactory;
    simulate(duckFactory);
    delete duckFactory;
    return 0;
}
