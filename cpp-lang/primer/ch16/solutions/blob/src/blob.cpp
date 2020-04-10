#include "blob.h"
#include "blobptr.h"
#include "constblobptr.h"

template<typename T> Blob<T>::Blob()
  : _data(std::make_shared<std::vector<T>>())
{
}

template<typename T>
template<typename Iter> Blob<T>::Blob(Iter b, Iter e)
  : _data(std::make_shared<std::vector<T>>(b, e))
{
}

template<typename T> Blob<T>::Blob(std::initializer_list<T> il)
  : _data(std::make_shared<std::vector<T>>(il))
{
}

template<typename T> void Blob<T>::pop_back()
{
  check(0, "Blob<T>::pop_back on empty Blob<T>");
  _data->pop_back;
}

template<typename T> T &Blob<T>::front()
{
  check(0, "Blob<T>::front on empty Blob<T>");
  return *(_data->begin());
}

template<typename T> const T &Blob<T>::front() const
{
  check(0, "const Blob<T>::front on empty Blob<T>");
  return *(_data->begin());
}

template<typename T> T &Blob<T>::back()
{
  check(0, "Blob<T>::back on empty Blob<T>");
  return *(_data->end() - 1);
}

template<typename T> const T &Blob<T>::back() const
{
  check(0, "const Blob<T>::back on empty Blob<T>");
  return *(_data->end() - 1);
}

template<typename T> BlobPtr<T> Blob<T>::begin()
{
  return BlobPtr<T>(*this);
}

template<typename T> BlobPtr<T> Blob<T>::end()
{
  return BlobPtr<T>(*this, size());
}

template<typename T> ConstBlobPtr<T> Blob<T>::begin() const
{
  return ConstBlobPtr<T>(*this);
}

template<typename T> ConstBlobPtr<T> Blob<T>::end() const
{
  return ConstBlobPtr<T>(*this, size());
}

template<typename T> ConstBlobPtr<T> Blob<T>::cbegin() const
{
  return ConstBlobPtr<T>(*this);
}

template<typename T> ConstBlobPtr<T> Blob<T>::cend() const
{
  return ConstBlobPtr<T>(*this, size());
}

template<typename T> void Blob<T>::check(size_type i, const std::string &msg) const
{
  if (i >= _data->size())
    throw std::out_of_range(msg);
}
