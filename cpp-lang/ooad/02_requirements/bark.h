#ifndef BARK_H
#define BARK_H

#include <string>
#include <iostream>

class Bark
{
public:
    explicit Bark(const std::string &sound);

private:
    std::string m_sound;

    friend bool operator==(const Bark &lhs, const Bark &rhs);
    friend bool operator!=(const Bark &lhs, const Bark &rhs);
    friend std::ostream &operator<<(std::ostream &out, const Bark &bark);
};

inline bool operator==(const Bark &lhs, const Bark &rhs)
{
    return lhs.m_sound == rhs.m_sound;
}

inline bool operator!=(const Bark &lhs, const Bark &rhs)
{
    return !(lhs == rhs);
}

inline std::ostream &operator<<(std::ostream &out, const Bark &bark)
{
    return out << bark.m_sound;
}

#endif // BARK_H
