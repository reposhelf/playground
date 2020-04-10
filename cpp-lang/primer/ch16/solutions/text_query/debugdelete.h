#ifndef DEBUGDELETE_H
#define DEBUGDELETE_H

#include <iostream>

class DebugDelete
{
public:
  template<typename T> void operator()(T *p) const
    {
      std::cout << "deleting a pointer" << std::endl;
      delete p;
    }
};

#endif
