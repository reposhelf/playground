#ifndef DEBUG_DELETE_H
#define DEBUG_DELETE_H

#include <iostream>

class debug_delete
{
public:
  template<typename T>
  void operator()(T *p) const
    {
      std::cout << "deleteing data" << std::endl;
      delete p;
    }
};

#endif