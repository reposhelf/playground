#include "dogdoor.h"
#include "automaticdoorcloser.h"

#include <iostream>
#include <thread>

using std::cout;
using std::endl;
using std::thread;

DogDoor::DogDoor()
    : m_isOpen(false)
{

}

void DogDoor::open()
{
    cout << "The dog door opens." << endl;
    m_isOpen = true;

    AutomaticDoorCloser adc(this);
    thread t(std::move(adc));
    t.detach();
}

void DogDoor::close()
{
    cout << "The dog door closes." << endl;
    m_isOpen = false;
}
