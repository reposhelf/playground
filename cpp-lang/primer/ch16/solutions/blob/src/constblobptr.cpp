#include "constblobptr.h"
#include "blob.h"

template<typename T> ConstBlobPtr<T>::ConstBlobPtr()
  : _curr(0)
{
}

template<typename T> ConstBlobPtr<T>::ConstBlobPtr(Blob<T> &blob, std::size_t sz)
  : _wptr(blob._data), _curr(sz)
{
}

template<typename T> const T &ConstBlobPtr<T>::operator*() const
{
  auto p = check(_curr, "dereference past end");
  return (*p)[_curr];
}

template<typename T> const T *ConstBlobPtr<T>::operator->() const
{
  return &(this->operator*());
}

template<typename T> std::shared_ptr<std::vector<T>> ConstBlobPtr<T>::check(std::size_t i,
		                                                            const std::string &msg) const
{
  auto ret = _wptr.lock();
  if (!ret)
    throw std::runtime_error("unbound ConstBlobPtr");
  if (i >= ret->size())
    throw std::out_of_range(msg);
  return ret;
}
