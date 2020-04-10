#ifndef DOGDOOR_H
#define DOGDOOR_H

class DogDoor
{
public:
    DogDoor();

    void open();
    void close();
    bool isOpen() const { return m_isOpen; }

private:
    bool m_isOpen;
};

#endif // DOGDOOR_H
