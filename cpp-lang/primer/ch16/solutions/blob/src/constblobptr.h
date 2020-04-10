#ifndef CONSTBLOBPTR_H
#define CONSTBLOBPTR_H

#include <memory>
#include <vector>
#include <string>

template<typename T> class ConstBlobPtr;
template<typename T> bool operator==(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
template<typename T> bool operator!=(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
template<typename T> class Blob;
template<typename T> class ConstBlobPtr
{
  friend bool operator==<T>(const ConstBlobPtr&, const ConstBlobPtr&);
  friend bool operator!=<T>(const ConstBlobPtr&, const ConstBlobPtr&);

public:
  ConstBlobPtr();
  ConstBlobPtr(Blob<T> &blob, std::size_t sz = 0);
  // access operations
  const T &operator*() const;
  const T *operator->() const;

private:
  std::shared_ptr<std::vector<T>> check(std::size_t, const std::string&) const;

  std::weak_ptr<std::vector<T>> _wptr;
  std::size_t _curr;
};

template<typename T> inline bool operator==(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs)
{
  return lhs.operator->() == rhs.operator->();
}

template<typename T> inline bool operator!=(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs)
{
  return !(lhs == rhs);
}

#endif
