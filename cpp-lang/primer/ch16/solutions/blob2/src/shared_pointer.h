#ifndef SHARED_POINTER_H
#define SHARED_POINTER_H

#include <functional>

template<typename T> class shared_pointer;
template<typename T> bool operator==(const shared_pointer<T>&, const shared_pointer<T>&);
template<typename T> bool operator!=(const shared_pointer<T>&, const shared_pointer<T>&);
template<typename T> bool operator< (const shared_pointer<T>&, const shared_pointer<T>&);
template<typename T> bool operator> (const shared_pointer<T>&, const shared_pointer<T>&);
template<typename T> bool operator<=(const shared_pointer<T>&, const shared_pointer<T>&);
template<typename T> bool operator>=(const shared_pointer<T>&, const shared_pointer<T>&);
template<typename T> class shared_pointer
{
  friend bool operator==<T>(const shared_pointer&, const shared_pointer&);
  friend bool operator!=<T>(const shared_pointer&, const shared_pointer&);
  friend bool operator< <T>(const shared_pointer&, const shared_pointer&);
  friend bool operator> <T>(const shared_pointer&, const shared_pointer&);
  friend bool operator<=<T>(const shared_pointer&, const shared_pointer&);
  friend bool operator>=<T>(const shared_pointer&, const shared_pointer&);
  
 public:
  shared_pointer(T *data)
    : _data(data),
      _ref_counter(new unsigned(1))
    {
    }

  shared_pointer(T *data, const std::function<void(T*)> &deleter)
    : _data(data),
      _ref_counter(new unsigned(1)),
      _deleter(deleter)
    {
    }

  shared_pointer(const shared_pointer &other)
    : _data(other._data),
      _ref_counter(other._ref_counter),
      _deleter(other._deleter)
    {
      ++(*_ref_counter);
    }
  
  shared_pointer &operator=(const shared_pointer &other)
    {
      if (this != &other)
      	{
          free();
          _data = other._data;
          _ref_counter = other._ref_counter;
          _deleter = other._deleter;
          ++(*_ref_counter);
        }
      return *this;
    }

  ~shared_pointer()
    {
      free();
    }

  T *get() const
    {
      return _data;
    }

  T &operator*() const
    {
      return *_data;
    }

  T *operator->() const
    {
      return _data;
    }

 private:
  void free()
    {
      if (!(--(*_ref_counter)))
      	{
          _deleter ? _deleter(_data) : delete _data;
          delete _ref_counter;
        }
    }
  
  T *_data;
  unsigned *_ref_counter;
  std::function<void(T*)> _deleter;
};

template<typename T> inline
bool operator==(const shared_pointer<T> &lhs, const shared_pointer<T> &rhs)
{
  return *lhs._data == *rhs._data;
}

template<typename T> inline
bool operator!=(const shared_pointer<T> &lhs, const shared_pointer<T> &rhs)
{
  return !(lhs == rhs);
}

template<typename T> inline
bool operator<(const shared_pointer<T> &lhs, const shared_pointer<T> &rhs)
{
  return *lhs._data < *rhs._data;
}

template<typename T> inline
bool operator>(const shared_pointer<T> &lhs, const shared_pointer<T> &rhs)
{
  return rhs < lhs;
}

template<typename T> inline
bool operator<=(const shared_pointer<T> &lhs, const shared_pointer<T> &rhs)
{
  return !(rhs < lhs);
}

template<typename T> inline
bool operator>=(const shared_pointer<T> &lhs, const shared_pointer<T> &rhs)
{
  return !(lhs < rhs);
}

#endif
