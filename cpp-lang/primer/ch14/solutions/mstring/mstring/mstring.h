#ifndef MSTRING_H
#define MSTRING_H

#include <memory>
#include <iostream>
#include <cstring>
#include <algorithm>

class String
{
public:
    String();
    String(const char *data);
    String(const String &other);
    String(String &&other) noexcept;
    String &operator=(const String &rhs);
    String &operator=(String &&rhs) noexcept;
    ~String();

    // Element access
    char &at(size_t pos);
    const char &at(size_t pos) const;
    char &operator[](size_t pos);
    const char &operator[](size_t pos) const;
    char &front();
    const char &front() const;
    char &back();
    const char &back() const;
    char *data();
    const char *data() const;

    // "Iterators"
    char *begin();
    const char *begin() const;
    const char *cbegin() const;
    char *end();
    const char *end() const;
    const char *cend() const;

    // Capacity
    bool empty() const;
    size_t size() const;
    size_t length() const;
    void reserve(size_t new_cap);
    size_t capacity() const;

    // Operations
    void clear();
    void push_back(char ch);
    void pop_back();
    void resize(size_t count, char ch = char());

private:
    void chk_n_alloc();
    std::pair<char *, char *> alloc_n_copy(const char *b, const char *e);
    void free();
    void reallocate();
    void reallocate_n(size_t new_cap);
    void fill_append(size_t count, char ch);
    void erase_at_end(size_t count);

    std::allocator<char> _alloc;
    char *_elements;
    char *_first_free;
    char *_cap;

    friend std::ostream &operator<<(std::ostream &os, const String &s);
    friend bool operator==(const String &lhs, const char *rhs);
    friend bool operator!=(const String &lhs, const char *rhs);
    friend bool operator==(const String &lhs, const String &rhs);
    friend bool operator!=(const String &lhs, const String &rhs);
    friend bool operator<(const String &lhs, const String &rhs);
    friend bool operator>(const String &lhs, const String &rhs);
    friend bool operator<=(const String &lhs, const String &rhs);
    friend bool operator>=(const String &lhs, const String &rhs);
};

inline std::ostream &operator<<(std::ostream &os, const String &s)
{
    return os << s._elements;
}

inline bool operator==(const String &lhs, const char *rhs)
{
    const size_t sz = std::strlen(rhs);
    return (lhs.size() == sz && std::equal(lhs.begin(), lhs.end(), rhs));
}

inline bool operator!=(const String &lhs, const char *rhs)
{
    return !(lhs == rhs);
}

inline bool operator==(const String &lhs, const String &rhs)
{
    return (lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

inline bool operator!=(const String &lhs, const String &rhs)
{
    return !(lhs == rhs);
}

inline bool operator<(const String &lhs, const String &rhs)
{
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

inline bool operator>(const String &lhs, const String &rhs)
{
    return !std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

inline bool operator<=(const String &lhs, const String &rhs)
{
    return lhs < rhs || lhs == rhs;
}

inline bool operator>=(const String &lhs, const String &rhs)
{
    return lhs > rhs || lhs == rhs;
}

#endif // MSTRING_H
