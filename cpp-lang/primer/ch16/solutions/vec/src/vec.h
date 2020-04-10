#ifndef VEC_H
#define VEC_H

#include <memory>
#include <algorithm>

template<typename T> class Vec;
template<typename T> bool operator==(const Vec<T>&, const Vec<T>&);
template<typename T> bool operator!=(const Vec<T>&, const Vec<T>&);
template<typename T> bool operator<(const Vec<T>&, const Vec<T>&);
template<typename T> bool operator>(const Vec<T>&, const Vec<T>&);
template<typename T> bool operator<=(const Vec<T>&, const Vec<T>&);
template<typename T> bool operator>=(const Vec<T>&, const Vec<T>&);
template<typename T> class Vec
{
  friend bool operator==<T>(const Vec&, const Vec&);
  friend bool operator!=<T>(const Vec&, const Vec&);
  friend bool operator< <T>(const Vec&, const Vec&);
  friend bool operator> <T>(const Vec&, const Vec&);
  friend bool operator<=<T>(const Vec&, const Vec&);
  friend bool operator>=<T>(const Vec&, const Vec&);
public:
  Vec();
  Vec(std::initializer_list<T> il);
  Vec(const Vec&);
  Vec(Vec&&) noexcept;
  Vec &operator=(const Vec&);
  Vec &operator=(Vec&&) noexcept;
  ~Vec();

  void push_back(const T&);
  void push_back(T&&);
  void resize(std::size_t, const T& = T());
  void reserve(std::size_t);
  std::size_t size() const;
  std::size_t capacity() const;
  T *begin() const;
  T *end() const;

private:
  // used by functions, which add elements into Vec
  void chk_n_alloc();
  // helper members, which used by copy constructor,
  // assignment operator and destructor
  std::pair<T*, T*> alloc_n_copy(const T*, const T*);
  void free(); // deletes elements and frees the memory space
  void reallocate(); // reserves more memory space and copies existed elements
  void reallocate_n(std::size_t);
  void fill_append(std::size_t, const T&);
  void erase_at_end(std::size_t);

  std::allocator<T> _alloc; // reserves elements
  T *_elements; // points to first element of the array
  T *_first_free; // points to first free element of the array
  T *_cap; // points to past of the last element in the array
};

template<typename T> inline bool operator==(const Vec<T> &lhs, const Vec<T> &rhs)
{
  return (lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template<typename T> inline bool operator!=(const Vec<T> &lhs, const Vec<T> &rhs)
{
  return !(lhs == rhs);
}

template<typename T> inline bool operator<(const Vec<T> &lhs, const Vec<T> &rhs)
{
  return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template<typename T> inline bool operator>(const Vec<T> &lhs, const Vec<T> &rhs)
{
  return rhs < lhs;
}

template<typename T> inline bool operator<=(const Vec<T> &lhs, const Vec<T> &rhs)
{
  return !(rhs < lhs);
}

template<typename T> inline bool operator>=(const Vec<T> &lhs, const Vec<T> &rhs)
{
  return !(lhs < rhs);
}

#endif
