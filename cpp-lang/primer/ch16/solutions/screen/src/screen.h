#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>

template<unsigned W, unsigned H> class Screen;
template<unsigned W, unsigned H> std::ostream &operator<<(std::ostream&, const Screen<W, H>&);
template<unsigned W, unsigned H> class Screen 
{
  friend std::ostream &operator<< <W, H>(std::ostream&, const Screen<W, H>&);
};

template<unsigned W, unsigned H> inline std::ostream &operator<<(std::ostream &os, const Screen<W, H> &s)
{
  os << "Screen::width = " << W << std::endl;
  os << "Screen::heignt = " << H;
  return os;
}

#endif
