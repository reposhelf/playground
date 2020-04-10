#ifndef BLOBPTR_H
#define BLOBPTR_H

#include <memory>
#include <vector>
#include <string>

template<typename T> class BlobPtr;
template<typename T> bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);
template<typename T> bool operator!=(const BlobPtr<T>&, const BlobPtr<T>&);
template<typename T> class Blob;
template<typename T> class BlobPtr
{
  friend bool operator==<T>(const BlobPtr&, const BlobPtr&);
  friend bool operator!=<T>(const BlobPtr&, const BlobPtr&);

public:
  BlobPtr();
  BlobPtr(Blob<T> &blob, std::size_t sz = 0);
  // prefix
  BlobPtr &operator++();
  BlobPtr &operator--();
  // postfix
  BlobPtr operator++(int);
  BlobPtr operator--(int);
  // arithmetic operations
  BlobPtr &operator+=(std::size_t n);
  BlobPtr &operator-=(std::size_t n);
  // access operations
  T &operator*() const;
  T *operator->() const;

private:
  std::shared_ptr<std::vector<T>> check(std::size_t, const std::string&) const;

  std::weak_ptr<std::vector<T>> _wptr;
  std::size_t _curr;
};

template<typename T> inline bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
  return lhs.operator->() == rhs.operator->();
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
