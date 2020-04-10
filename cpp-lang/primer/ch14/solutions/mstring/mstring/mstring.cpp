#include "mstring.h"

#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>

String::String()
    : _elements(nullptr),
      _first_free(nullptr),
      _cap(nullptr)
{
    // empty
}

String::String(const char *data)
    : _elements(nullptr),
      _first_free(nullptr),
      _cap(nullptr)
{
    const auto sz = std::strlen(data);
    reserve(sz);
    for (size_t i = 0; i < sz; ++i)
        push_back(data[i]);

}

String::String(const String &other)
{
    std::cout << "String::String(const String &other)" << std::endl;

    auto newdata = alloc_n_copy(other.begin(), other.end());
    _elements = newdata.first;
    _first_free = _cap = newdata.second;
}

String::String(String &&other) noexcept
    : _elements(other._elements),
      _first_free(other._first_free),
      _cap(other._cap)
{
    std::cout << "String::String(String &&other) noexcept" << std::endl;

    other._elements = other._first_free = other._cap = nullptr;
}

String &String::operator=(const String &rhs)
{
    std::cout << "String &String::operator=(const String &rhs)" << std::endl;

    auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    _elements = newdata.first;
    _first_free = _cap = newdata.second;
    return *this;
}

String &String::operator=(String &&rhs) noexcept
{
    std::cout << "String &String::operator=(String &&rhs) noexcept" << std::endl;

    if (this != &rhs) {
        free();
        _elements = rhs._elements;
        _first_free = rhs._first_free;
        _cap = rhs._cap;
        rhs._elements = rhs._first_free = rhs._cap = nullptr;
    }
    return *this;
}

String::~String()
{
    free();
}

char &String::at(size_t pos)
{
    assert(pos < size());
    return *(_elements + pos);
}

const char &String::at(size_t pos) const
{
    assert(pos < size());
    return *(_elements + pos);
}

char &String::operator[](size_t pos)
{
    return at(pos);
}

const char &String::operator[](size_t pos) const
{
    return at(pos);
}

char &String::front()
{
    assert(!empty());
    return *_elements;
}

const char &String::front() const
{
    assert(!empty());
    return *_elements;
}

char &String::back()
{
    assert(!empty());
    return *(_first_free - 1);
}

const char &String::back() const
{
    assert(!empty());
    return *(_first_free - 1);
}

char *String::data()
{
    return _elements;
}

const char *String::data() const
{
    return _elements;
}

char *String::begin()
{
    return _elements;
}

const char *String::begin() const
{
    return _elements;
}

const char *String::cbegin() const
{
    return _elements;
}

char *String::end()
{
    return _first_free;
}

const char *String::end() const
{
    return _first_free;
}

const char *String::cend() const
{
    return _first_free;
}

bool String::empty() const
{
    return size() == 0;
}

size_t String::size() const
{
    return _first_free - _elements;
}

size_t String::length() const
{
    return size();
}

void String::reserve(size_t new_cap)
{
    reallocate_n(new_cap);
}

size_t String::capacity() const
{
    return _cap - _elements;
}

void String::clear()
{
    free();
}

void String::push_back(char ch)
{
    chk_n_alloc();
    _alloc.construct(_first_free++, ch);
}

void String::pop_back()
{
    assert(!empty());
    _alloc.destroy(--_first_free);
}

void String::resize(size_t count, char ch)
{
    if (size() <= count)
        fill_append(count - size(), ch);
    else if (size() > count)
        erase_at_end(size() - count);
}

void String::chk_n_alloc()
{
    if (size() == capacity())
        reallocate();
}

std::pair<char *, char *> String::alloc_n_copy(const char *b, const char *e)
{
    auto newdata = _alloc.allocate(e - b);
    return {newdata, std::uninitialized_copy(b, e, newdata)};
}

void String::free()
{
    std::for_each(_elements, _first_free, [this](char &ch){_alloc.destroy(&ch);});
    _alloc.deallocate(_elements, _cap - _elements);
    _elements = _first_free = _cap = nullptr;
}

void String::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = _alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = _elements;
    for (size_t i = 0; i != size(); ++i)
        _alloc.construct(dest++, std::move(*elem++));
    free();
    _elements = newdata;
    _first_free = dest;
    _cap = _elements + newcapacity;
}

void String::reallocate_n(size_t new_cap)
{
    if (capacity() < new_cap) {
        auto newdata = _alloc.allocate(new_cap);
        auto dest = newdata;
        auto elem = _elements;
        for (size_t i = 0; i != size(); ++i)
            _alloc.construct(dest++, std::move(*elem++));
        free();
        _elements = newdata;
        _first_free = dest;
        _cap = _elements + new_cap;
    }
}

void String::fill_append(size_t count, char ch)
{
    for (/* empty */ ; count != 0; --count)
        push_back(ch);
}

void String::erase_at_end(size_t count)
{
    for (/* empty */; count != 0; --count)
        _alloc.destroy(--_first_free);
}
