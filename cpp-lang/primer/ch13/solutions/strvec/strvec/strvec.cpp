#include "strvec.h"

#include <algorithm>

using namespace std;

StrVec::StrVec()
    : _elements(nullptr),
      _first_free(nullptr),
      _cap(nullptr)
{
}

StrVec::StrVec(std::initializer_list<string> il)
    : _elements(nullptr),
      _first_free(nullptr),
      _cap(nullptr)
{
    reserve(il.size());
    for (auto const &s : il)
        push_back(s);
}

StrVec::StrVec(const StrVec &other)
{
    auto newdata = alloc_n_copy(other.begin(), other.end());
    _elements = newdata.first;
    _first_free = _cap = newdata.second;
}

StrVec::StrVec(StrVec &&other) noexcept
    : _elements(other._elements),
      _first_free(other._first_free),
      _cap(other._cap)
{
    other._elements = other._first_free = other._cap = nullptr;
}

StrVec &StrVec::operator=(const StrVec &rhs)
{
    auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    _elements = newdata.first;
    _first_free = _cap = newdata.second;
    return *this;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept
{
    if (this != &rhs) {
        free();
        _elements = rhs._elements;
        _first_free = rhs._first_free;
        _cap = rhs._cap;
        rhs._elements = rhs._first_free = rhs._cap = nullptr;
    }
    return *this;
}

StrVec::~StrVec()
{
    free();
}

void StrVec::push_back(const std::string &s)
{
    chk_n_alloc();
    _alloc.construct(_first_free++, s);
}

void StrVec::push_back(string &&s)
{
    chk_n_alloc();
    _alloc.construct(_first_free++, std::move(s));
}

void StrVec::resize(size_t count, const string &s)
{
    if (size() < count)
        fill_append(count - size(), s);
    else if (size() > count)
        erase_at_end(size() - count);
}

void StrVec::reserve(size_t new_cap)
{
    reallocate_n(new_cap);
}

size_t StrVec::size() const
{
    return _first_free - _elements;
}

size_t StrVec::capacity() const
{
    return _cap - _elements;
}

std::string *StrVec::begin() const
{
    return _elements;
}

std::string *StrVec::end() const
{
    return _first_free;
}

void StrVec::chk_n_alloc()
{
    if (size() == capacity())
        reallocate();
}

std::pair<std::string *, std::string *> StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
    auto data = _alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    for_each(_elements, _first_free, [this](string &p) { _alloc.destroy(&p); });
    _alloc.deallocate(_elements, _cap - _elements);
}

void StrVec::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;
    auto first = _alloc.allocate(newcapacity);
    auto last = uninitialized_copy(make_move_iterator(begin()), make_move_iterator(end()), first);
    free();
    _elements = first;
    _first_free = last;
    _cap = _elements + newcapacity;
}

void StrVec::reallocate_n(size_t new_cap)
{
    if (capacity() < new_cap) {
        auto first = _alloc.allocate(new_cap);
        auto last = uninitialized_copy(make_move_iterator(begin()), make_move_iterator(end()), first);
        free();
        _elements = first;
        _first_free = last;
        _cap = _elements + new_cap;
    }
}

void StrVec::fill_append(size_t count, const string &s)
{
    for (/* empty */ ; count != 0; --count)
        push_back(s);
}

void StrVec::erase_at_end(size_t count)
{
    for (/* empty */; count != 0; --count)
        _alloc.destroy(--_first_free);
}
