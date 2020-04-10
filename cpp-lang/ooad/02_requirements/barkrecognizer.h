#ifndef BARKRECOGNIZER_H
#define BARKRECOGNIZER_H

#include "bark.h"

#include <string>
#include <vector>
#include <initializer_list>

class DogDoor;
class BarkRecognizer
{
public:
    BarkRecognizer(DogDoor *door);
    BarkRecognizer(DogDoor *door, std::initializer_list<Bark> init);
    void recognize(const Bark &bark) const;
    void addBark(const Bark &bark);

private:
    DogDoor *m_door;
    std::vector<Bark> m_allowedBarks;
};

#endif // BARKRECOGNIZER_H
