#ifndef BLOB_H
#define BLOB_H

#include "shared_pointer.h"
#include "blobptr.h"
#include "constblobptr.h"
#include "debug_delete.h"

#include <vector>
#include <algorithm>
#include <initializer_list>
#include <string>

template<typename T> class BlobPtr;
template<typename T> class ConstBlobPtr;
template<typename T> class Blob;
template<typename T> bool operator==(const Blob<T>&, const Blob<T>&);
template<typename T> bool operator!=(const Blob<T>&, const Blob<T>&);
template<typename T> bool operator<(const Blob<T>&, const Blob<T>&);
template<typename T> bool operator>(const Blob<T>&, const Blob<T>&);
template<typename T> bool operator<=(const Blob<T>&, const Blob<T>&);
template<typename T> bool operator>=(const Blob<T>&, const Blob<T>&);
template<typename T> class Blob
{
  friend class BlobPtr<T>;
  friend class ConstBlobPtr<T>;
  friend bool operator==<T>(const Blob&, const Blob&);
  friend bool operator!=<T>(const Blob&, const Blob&);
  friend bool operator< <T>(const Blob&, const Blob&);
  friend bool operator> <T>(const Blob&, const Blob&);
  friend bool operator<=<T>(const Blob&, const Blob&);
  friend bool operator>=<T>(const Blob&, const Blob&);

public:
  typedef typename std::vector<T>::size_type size_type;
  
  Blob() : _data(new std::vector<T>(), debug_delete())
    {
    }
  
  template<typename Iter> Blob(Iter b, Iter e) : _data(new std::vector<T>(b, e), debug_delete())
    {
    }
  
  explicit Blob(std::initializer_list<T> il) : _data(new std::vector<T>(il), debug_delete())
    {
    }

  T &operator[](size_type n)
    {
      return *(begin() + n);
    }
  
  const T &operator[](size_type n) const
    {
      return *(begin() + n);
    }
  
  size_type size() const
    {
      return _data->size();
    }
  
  bool empty() const
    {
      return _data->empty();
    }
  
  void push_back(const T &v)
    {
      _data->push_back(v);
    }
  
  void pop_back()
    {
      check(0, "Blob<T>::pop_back on empty Blob<T>");
      _data->pop_back();
    }

  T &front()
    {
      check(0, "Blob<T>::front on empty Blob<T>");
      return *(_data->begin());
    }
  
  const T &front() const
    {
      check(0, "const Blob<T>::front on empty Blob<T>");
      return *(_data->begin());
    }
  
  T &back()
    {
      check(0, "Blob<T>::back on empty Blob<T>");
      return *(_data->end() - 1);
    }
  
  const T &back() const
    {
      check(0, "const Blob<T>::back on empty Blob<T>");
      return *(_data->end() - 1);
    }

  BlobPtr<T> begin()
    {
      return BlobPtr<T>(*this);
    }
  
  BlobPtr<T> end()
    {
      return BlobPtr<T>(*this, size());
    }

  ConstBlobPtr<T> begin() const
    {
      return ConstBlobPtr<T>(*this);
    }
  
  ConstBlobPtr<T> end() const
    {
      return ConstBlobPtr<T>(*this, size());
    }

  ConstBlobPtr<T> cbegin() const
    {
      return ConstBlobPtr<T>(*this);
    }
  
  ConstBlobPtr<T> cend() const
    {
      return ConstBlobPtr<T>(*this, size());
    }

private:
  void check(size_type i, const std::string &msg) const
    {
      if (i >= _data->size())
        throw std::out_of_range(msg);
    }

  shared_pointer<std::vector<T>> _data;
};

template<typename T> inline bool operator==(const Blob<T> &lhs, const Blob<T> &rhs)
{
  return *(lhs._data) == *(rhs._data);
}

template<typename T> inline bool operator!=(const Blob<T> &lhs, const Blob<T> &rhs)
{
  return !(lhs == rhs);
}

template<typename T> inline bool operator<(const Blob<T> &lhs, const Blob<T> &rhs)
{
  return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template<typename T> inline bool operator>(const Blob<T> &lhs, const Blob<T> &rhs)
{
  return rhs < lhs;
}

template<typename T> inline bool operator<=(const Blob<T> &lhs, const Blob<T> &rhs)
{
  return !(rhs < lhs);
}

template<typename T> inline bool operator>=(const Blob<T> &lhs, const Blob<T> &rhs)
{
  return !(lhs < rhs);
}

#endif
