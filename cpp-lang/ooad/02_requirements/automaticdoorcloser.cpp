#include "automaticdoorcloser.h"
#include "dogdoor.h"

#include <iostream>
#include <chrono>
#include <thread>

AutomaticDoorCloser::AutomaticDoorCloser(DogDoor *door, int interval)
    : m_door(door),
      m_interval(interval)
{

}

AutomaticDoorCloser::AutomaticDoorCloser(AutomaticDoorCloser &&other) noexcept
    : m_door(other.m_door),
      m_interval(other.m_interval)
{
    other.m_door = nullptr;
}

void AutomaticDoorCloser::operator()()
{
    std::this_thread::sleep_for(std::chrono::seconds(m_interval));
    if (m_door && m_door->isOpen()) {
        m_door->close();
    }
}
