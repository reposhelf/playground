#ifndef BLOB_H
#define BLOB_H

#include <memory>
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
  Blob();
  template<typename Iter> Blob(Iter b, Iter e);
  explicit Blob(std::initializer_list<T> li);

  T &operator[](size_type n) { return _data->begin() + n; }
  const T &operator[](size_type n) const { return _data->begin() + n; }
  size_type size() const { return _data->size(); }
  bool empty() const { return _data->empty(); }

  void push_back(const T &v) { _data->push_back(v); }
  void pop_back();

  T &front();
  const T &front() const;
  T &back();
  const T &back() const;

  BlobPtr<T> begin();
  BlobPtr<T> end();

  ConstBlobPtr<T> begin() const;
  ConstBlobPtr<T> end() const;

  ConstBlobPtr<T> cbegin() const;
  ConstBlobPtr<T> cend() const;

private:
  void check(size_type i, const std::string &msg) const;
  std::shared_ptr<std::vector<T>> _data;
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
