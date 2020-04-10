#ifndef UNIQUE_POINTER_H
#define UNIQUE_POINTER_H

template<typename T> struct default_deleter
{
  void operator()(T *p)
    {
      delete p;
    }
};

template<typename T> struct default_deleter<T[]>
{
  void operator()(T *p)
    {
      delete[] p;
    }
};

template<typename T, typename Deleter> class unique_pointer;
template<typename T, typename Deleter> 
bool operator==(const unique_pointer<T, Deleter>&, const unique_pointer<T, Deleter>&);
template<typename T, typename Deleter>
bool operator!=(const unique_pointer<T, Deleter>&, const unique_pointer<T, Deleter>&);
template<typename T, typename Deleter>
bool operator< (const unique_pointer<T, Deleter>&, const unique_pointer<T, Deleter>&);
template<typename T, typename Deleter>
bool operator> (const unique_pointer<T, Deleter>&, const unique_pointer<T, Deleter>&);
template<typename T, typename Deleter>
bool operator<=(const unique_pointer<T, Deleter>&, const unique_pointer<T, Deleter>&);
template<typename T, typename Deleter>
bool operator>=(const unique_pointer<T, Deleter>&, const unique_pointer<T, Deleter>&);
template<typename T, typename Deleter = default_deleter<T>> class unique_pointer
{
  friend bool operator==<T, Deleter>(const unique_pointer&, const unique_pointer&);
  friend bool operator!=<T, Deleter>(const unique_pointer&, const unique_pointer&);
  friend bool operator< <T, Deleter>(const unique_pointer&, const unique_pointer&);
  friend bool operator> <T, Deleter>(const unique_pointer&, const unique_pointer&);
  friend bool operator<=<T, Deleter>(const unique_pointer&, const unique_pointer&);
  friend bool operator>=<T, Deleter>(const unique_pointer&, const unique_pointer&);
  
 public:
  unique_pointer(T *data)
    : _data(data)
    {
    }

  unique_pointer(T *data, const Deleter &deleter)
    : _data(data),
      _deleter(deleter)
    {
    }

  unique_pointer(unique_pointer &&other)
    : _data(std::move(other._data)),
      _deleter(std::move(other._deleter))
    {
      other._data = nullptr;
    }
  
  unique_pointer &operator=(unique_pointer &&other)
    {
      if (this != &other)
        {
          _data = std::move(other._data);
          _deleter = std::move(other._deleter);
          other._data = nullptr;
        }
      return *this;
    }

  ~unique_pointer()
    {
      if (_data != nullptr)
        _deleter(_data);
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

  unique_pointer(const unique_pointer &) = delete;
  unique_pointer &operator=(const unique_pointer &) = delete;

 private:

  T *_data;
  Deleter _deleter;
};

template<typename T, typename Deleter>
inline bool
operator==(const unique_pointer<T, Deleter> &lhs, const unique_pointer<T, Deleter> &rhs)
{
  return *lhs._data == *rhs._data;
}

template<typename T, typename Deleter>
inline bool
operator!=(const unique_pointer<T, Deleter> &lhs, const unique_pointer<T, Deleter> &rhs)
{
  return !(lhs == rhs);
}

template<typename T, typename Deleter>
inline bool
operator<(const unique_pointer<T, Deleter> &lhs, const unique_pointer<T, Deleter> &rhs)
{
  return *lhs._data < *rhs._data;
}

template<typename T, typename Deleter>
inline bool
operator>(const unique_pointer<T, Deleter> &lhs, const unique_pointer<T, Deleter> &rhs)
{
  return rhs < lhs;
}

template<typename T, typename Deleter>
inline bool
operator<=(const unique_pointer<T, Deleter> &lhs, const unique_pointer<T, Deleter> &rhs)
{
  return !(rhs < lhs);
}

template<typename T, typename Deleter>
inline bool
operator>=(const unique_pointer<T, Deleter> &lhs, const unique_pointer<T, Deleter> &rhs)
{
  return !(lhs < rhs);
}

#endif
