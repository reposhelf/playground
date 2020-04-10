#ifndef TEMPLATE_FUNCTION_H
#define TEMPLATE_FUNCTION_H

#include <cstring>
#include <iostream>

template<typename T> int compare(const T &a, const T &b)
{
  if (a < b)
    return -1;
  if (b < a)
    return 1;
  return 0;
}

template<std::size_t N, std::size_t M> int compare(const char (&a)[N], const char (&b)[M])
{
  return strcmp(a, b);
}

template<typename Iter, typename T> Iter find(Iter first, Iter last, const T &value)
{
  for (; first != last; ++first)
    {
      if (*first == value)
	return first;
    }
  return last;
}

template<typename T, std::size_t N> void printa(const T (&a)[N])
{
  std::cout << '[';
  for (decltype(N) i = 0; i != N; ++i)
    {
      std::cout << a[i];
      if (i != N - 1)
  	std::cout << ", ";
    }
  std::cout << ']' << std::endl;
}

template<std::size_t N> void printa(const char (&a)[N])
{
  std::cout << '[';
  for (decltype(N) i = 0; a[i] != '\0'; ++i)
    {
      std::cout << a[i];
      if (a[i + 1] != '\0')
	std::cout << ", ";
    }
  std::cout << ']' << std::endl;
}

template<typename T, std::size_t N> T *begin(T (&a)[N])
{
  return &a[0];
}

template<typename T, std::size_t N> T *end(T (&a)[N])
{
  return &a[N];
}

template<typename T, std::size_t N> constexpr auto sizea(const T (&)[N]) -> decltype(N)
{
  return N;
}

template<typename T> void printc(const T &seq)
{
  typename T::size_type sz = seq.size();
  for (typename T::size_type i = 0; i != sz; ++i)
    std::cout << seq[i] << ' ';
  std::cout << std::endl;
}

template<typename T> void printc_2(const T &seq)
{
  auto e = seq.end();
  for (auto b = seq.begin(); b != e; ++b)
    std::cout << *b << ' ';
  std::cout << std::endl;
}

#endif
