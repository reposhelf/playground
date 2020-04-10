#include "barkrecognizer.h"
#include "dogdoor.h"

#include <iostream>
#include <algorithm>
#include <cassert>

BarkRecognizer::BarkRecognizer(DogDoor *door)
    : m_door(door)
{

}

BarkRecognizer::BarkRecognizer(DogDoor *door, std::initializer_list<Bark> init)
    : m_door(door),
      m_allowedBarks(init)
{

}

void BarkRecognizer::recognize(const Bark &bark) const
{
    std::cout << "\tBarkRecognizer: Heard a '" << bark << "'" << std::endl;

    auto ret = std::find(m_allowedBarks.cbegin(), m_allowedBarks.cend(), bark);
    if (ret == m_allowedBarks.cend()) {
        std::cout << "This dog is not allowed." << std::endl;
        return;
    }

    assert(m_door);
    m_door->open();
}

void BarkRecognizer::addBark(const Bark &bark)
{
    m_allowedBarks.push_back(bark);
}
