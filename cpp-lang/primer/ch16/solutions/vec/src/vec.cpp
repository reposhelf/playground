#include "vec.h"

template<typename T> Vec<T>::Vec()
  : _elements(nullptr),
    _first_free(nullptr),
    _cap(nullptr)
{
}

template<typename T> Vec<T>::Vec(std::initializer_list<T> il)
  : _elements(nullptr),
    _first_free(nullptr),
    _cap(nullptr)
{
  reserve(il.size());
  for (auto const &s : il)
    push_back(s);
}

template<typename T> Vec<T>::Vec(const Vec &other)
{
  auto newdata = alloc_n_copy(other.begin(), other.end());
  _elements = newdata.first;
  _first_free = _cap = newdata.second;
}

template<typename T> Vec<T>::Vec(Vec &&other) noexcept
  : _elements(other._elements),
    _first_free(other._first_free),
    _cap(other._cap)
{
  other._elements = other._first_free = other._cap = nullptr;
}

template<typename T> Vec<T> &Vec<T>::operator=(const Vec &other)
{
  auto newdata = alloc_n_copy(other.begin(), other.end());
  free();
  _elements = newdata.first;
  _first_free = _cap = newdata.second;
  return *this;
}

template<typename T> Vec<T> &Vec<T>::operator=(Vec &&other) noexcept
{
  if (this != &other)
    {
      free();
      _elements = other._elements;
      _first_free = other._first_free;
      _cap = other._cap;
      other._elements = other._first_free = other._cap = nullptr;
    }
  return *this;
}

template<typename T> Vec<T>::~Vec()
{
  free();
}

template<typename T> void Vec<T>::push_back(const T &v)
{
  chk_n_alloc();
  _alloc.construct(_first_free++, v);
}

template<typename T> void Vec<T>::push_back(T &&v)
{
  chk_n_alloc();
  _alloc.cunstruct(_first_free++, std::move(v));
}

template<typename T> void Vec<T>::resize(std::size_t count, const T &v)
{
  if (size() < count)
    fill_append(count - size(), v);
  else if (size() > count)
    erase_at_end(size() - count);
}

template<typename T> void Vec<T>::reserve(std::size_t count)
{
  reallocate_n(count);
}

template<typename T> std::size_t Vec<T>::size() const
{
  return _first_free - _elements;
}

template<typename T> std::size_t Vec<T>::capacity() const
{
  return _cap - _elements;
}

template<typename T> T *Vec<T>::begin() const
{
  return _elements;
}

template<typename T> T *Vec<T>::end() const
{
  return _first_free;
}

template<typename T> void Vec<T>::chk_n_alloc()
{
  if (size() == capacity())
    reallocate();
}

template<typename T> std::pair<T*, T*> Vec<T>::alloc_n_copy(const T *b, const T *e)
{
  auto data = _alloc.allocate(e - b);
  return {data, std::uninitialized_copy(b, e, data)};
}

template<typename T> void Vec<T>::free()
{
  std::for_each(_elements, _first_free, [this](T &p){_alloc.destroy(&p);});
  _alloc.deallocate(_elements, _cap - _elements);
}

template<typename T> void Vec<T>::reallocate()
{
  auto newcapacity = size() ? 2 * size() : 1;
  auto first = _alloc.allocate(newcapacity);
  auto last = std::uninitialized_copy(std::make_move_iterator(begin()),
		                      std::make_move_iterator(end()), first);
  free();
  _elements = first;
  _first_free = last;
  _cap = _elements + newcapacity;
}

template<typename T> void Vec<T>::reallocate_n(std::size_t new_cap)
{
  if (capacity() < new_cap)
    {
      auto first = _alloc.allocate(new_cap);
      auto last = std::uninitialized_copy(std::make_move_iterator(begin()), 
		                          std::make_move_iterator(end()), first);
      free();
      _elements = first;
      _first_free = last;
      _cap = _elements + new_cap;
    }
}

template<typename T> void Vec<T>::fill_append(std::size_t count, const T &v)
{
  for (/* empty */; count != 0; --count)
    push_back(v);
}

template<typename T> void Vec<T>::erase_at_end(std::size_t count)
{
  for (/* empty */; count != 0; --count)
    _alloc.destroy(--_first_free);
}
