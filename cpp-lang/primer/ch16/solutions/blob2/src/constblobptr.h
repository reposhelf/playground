#ifndef CONSTBLOBPTR_H
#define CONSTBLOBPTR_H

#include "blob.h"

#include <vector>
#include <string>
#include <stdexcept>

template<typename T> class ConstBlobPtr;
template<typename T> bool operator==(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
template<typename T> bool operator!=(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
template<typename T> class Blob;
template<typename T> class ConstBlobPtr
{
  friend bool operator==<T>(const ConstBlobPtr&, const ConstBlobPtr&);
  friend bool operator!=<T>(const ConstBlobPtr&, const ConstBlobPtr&);

public:
  ConstBlobPtr() : _curr(0)
    {
    }
  
  ConstBlobPtr(Blob<T> &blob, std::size_t sz = 0)
    : _ptr(blob._data.get()), _curr(sz)
    {
    }
  
  // access operations
  const T &operator*() const
    {
      check(_curr, "dereference past end");
      return (*_ptr)[_curr];
    }
  
  const T *operator->() const
    {
      return &(this->operator*());
    }

private:
  void check(std::size_t i, const std::string &msg) const
    {
      if (!_ptr)
	throw std::runtime_error("unbound ConstBlobPtr");
      if (i >= _ptr->size())
	throw std::out_of_range(msg);
    }

  std::vector<T> *_ptr;
  std::size_t _curr;
};

template<typename T> inline bool operator==(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs)
{
  return (lhs._ptr == rhs._ptr && lhs._curr == rhs._curr);
}

template<typename T> inline bool operator!=(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs)
{
  return !(lhs == rhs);
}

#endif
