#include "blobptr.h"
#include "blob.h"

template<typename T> BlobPtr<T>::BlobPtr()
  : _curr(0)
{
}

template<typename T> BlobPtr<T>::BlobPtr(Blob<T> &blob, std::size_t sz)
  : _wptr(blob._data), _curr(sz)
{
}

template<typename T> BlobPtr<T> &BlobPtr<T>::operator++()
{
  check(_curr, "increment past end of BlobPtr");
  ++_curr;
  return *this;
}

template<typename T> BlobPtr<T> &BlobPtr<T>::operator--()
{
  check(--_curr, "decrement past begin of BlobPtr");
  return *this;
}

template<typename T> BlobPtr<T> BlobPtr<T>::operator++(int)
{
  BlobPtr ret = *this;
  ++*this;
  return ret;
}

template<typename T> BlobPtr<T> BlobPtr<T>::operator--(int)
{
  BlobPtr ret = *this;
  --*this;
  return ret;
}

template<typename T> BlobPtr<T> &BlobPtr<T>::operator+=(std::size_t n)
{
  check(_curr + n, "arithmetic '+' past end of BlobPtr");
  _curr += n;
  return *this;
}

template<typename T> BlobPtr<T> &BlobPtr<T>::operator-=(std::size_t n)
{
  check(_curr - n, "arithmetic '-' past begin of BlobPtr");
  _curr -= n;
  return *this;
}

template<typename T> T &BlobPtr<T>::operator*() const
{
  auto p = check(_curr, "dereference past end");
  return (*p)[_curr];
}

template<typename T> T *BlobPtr<T>::operator->() const
{
  return &(this->operator*());
}

template<typename T> std::shared_ptr<std::vector<T>> BlobPtr<T>::check(std::size_t i,
		                                                       const std::string &msg) const
{
  auto ret = _wptr.lock();
  if (!ret)
    throw std::runtime_error("nbound BlobPtr");
  if (i >= ret->size)
    throw std::out_of_range(msg);
  return ret;
}
