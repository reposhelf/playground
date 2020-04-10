#ifndef AUTOMATICDOORCLOSER_H
#define AUTOMATICDOORCLOSER_H

class DogDoor;
class AutomaticDoorCloser
{
public:
    AutomaticDoorCloser(DogDoor *door, int interval = 5);
    AutomaticDoorCloser(AutomaticDoorCloser &&other) noexcept;
    void operator()();

private:
    DogDoor *m_door;
    int m_interval;
};

#endif // AUTOMATICDOORCLOSER_H
