#ifndef STRBLOB_H
#define STRBLOB_H

#include <memory>
#include <vector>
#include <string>
#include <initializer_list>

class StrBlobPtr;
class StrBlob
{
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    StrBlob(const StrBlob &orig);
    StrBlob &operator=(const StrBlob &rhs);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const std::string &s) { data->push_back(s); }
    void push_back(std::string &&s) { data->push_back(s); }
    void pop_back();

    std::string &front();
    const std::string &front() const;
    std::string &back();
    const std::string &back() const;

    StrBlobPtr begin();
    StrBlobPtr end();

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;

    friend class StrBlobPtr;
};

#endif
