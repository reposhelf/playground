#ifndef STRVEC_H
#define STRVEC_H

#include <memory>
#include <string>

class StrVec
{
public:
    StrVec();
    StrVec(std::initializer_list<std::string> il);
    StrVec(const StrVec&);
    StrVec(StrVec&&) noexcept;
    StrVec &operator=(const StrVec&);
    StrVec &operator=(StrVec&&) noexcept;
    ~StrVec();

    void push_back(const std::string&);
    void push_back(std::string&&);
    void resize(size_t count, const std::string &s = std::string());
    void reserve(size_t new_cap);
    size_t size() const;
    size_t capacity() const;
    std::string *begin() const;
    std::string *end() const;

private:
    // used by functions, which add elements into StrVec
    void chk_n_alloc();
    // helper members, which used by copy constructor,
    // assignment operator and destructor
    std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
    void free(); // deletes elements and frees the memory space
    void reallocate(); // reserves more the memory space and copies existed elements
    void reallocate_n(size_t new_cap);
    void fill_append(size_t count, const std::string &s);
    void erase_at_end(size_t count);

    std::allocator<std::string> _alloc; // reserves elements
    std::string *_elements; // points to first element of the array
    std::string *_first_free; // points to first free element of the array
    std::string *_cap; // points to past of the last element in the array
};

#endif // STRVEC_H
