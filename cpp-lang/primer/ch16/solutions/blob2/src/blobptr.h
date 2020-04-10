#ifndef BLOBPTR_H
#define BLOBPTR_H

#include "blob.h"

#include <vector>
#include <string>
#include <stdexcept>

#include <iostream>

template<typename T> class BlobPtr;
template<typename T> bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);
template<typename T> bool operator!=(const BlobPtr<T>&, const BlobPtr<T>&);
template<typename T> class Blob;
template<typename T> class BlobPtr
{
  friend bool operator==<T>(const BlobPtr&, const BlobPtr&);
  friend bool operator!=<T>(const BlobPtr&, const BlobPtr&);

public:
  BlobPtr() : _curr(0)
    {
    }
  
  BlobPtr(Blob<T> &blob, std::size_t sz = 0)
    : _ptr(blob._data.get()), _curr(sz)
    {
    }
  
  // prefix
  BlobPtr &operator++()
    {
      check(_curr, "increment past end of BlobPtr");
      ++_curr;
      return *this;
    }
    
  BlobPtr &operator--()
    {
      check(--_curr, "decrement past begin of BlobPtr");
      return *this;

    }
    
  // postfix
  BlobPtr operator++(int)
    {
      BlobPtr ret = *this;
      ++*this;
      return ret;
    }
    
  BlobPtr operator--(int)
    {
      BlobPtr ret = *this;
      --*this;
      return ret;
    }
  
  // arithmetic operations
  BlobPtr &operator+=(std::size_t n)
    {
      check(_curr + n, "arithmetic '+' past end of BlobPtr");
      _curr += n;
      return *this;
    }
  
  BlobPtr &operator-=(std::size_t n)
    {
      check(_curr - n, "arithmetic '-' past begin of BlobPtr");
      _curr -= n;
      return *this;
    }
  
  // access operations
  T &operator*() const
    {
      check(_curr, "dereference past end");
      return (*_ptr)[_curr];
    }
  
  T *operator->() const
    {
      return &(this->operator*());
    }

private:
  void check(std::size_t i, const std::string &msg) const
    {
      if (!_ptr)
	throw std::runtime_error("nbound BlobPtr");
      if (i >= _ptr->size())
	throw std::out_of_range(msg);
    }

  std::vector<T> *_ptr;
  std::size_t _curr;
};

template<typename T> inline bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
  return (lhs._ptr == rhs._ptr && lhs._curr == rhs._curr);
}

template<typename T> inline bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
  return !(lhs == rhs);
}

template<typename T> BlobPtr<T> operator+(const BlobPtr<T> &bp, std::size_t n)
{
  BlobPtr<T> ret = bp;
  ret += n;
  return ret;
}

template<typename T> BlobPtr<T> operator-(const BlobPtr<T> &bp, std::size_t n)
{
  BlobPtr<T> ret = bp;
  ret -= n;
  return ret;
}

#endif
