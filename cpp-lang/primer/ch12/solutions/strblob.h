#ifndef STRBLOB_H
#define STRBLOB_H

#include <memory>
#include <vector>
#include <string>
#include <initializer_list>

class StrBlobPtr;
class ConstStrBlobPtr;
class StrBlob
{
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    explicit StrBlob(std::initializer_list<std::string> il);
    size_type size() const { return _data->size(); }
    bool empty() const { return _data->empty(); }

    void push_back(const std::string &s) { _data->push_back(s); }
    void pop_back();

    std::string &front();
    const std::string &front() const;
    std::string &back();
    const std::string &back() const;

    StrBlobPtr begin();
    StrBlobPtr end();

    ConstStrBlobPtr begin() const;
    ConstStrBlobPtr end() const;

    ConstStrBlobPtr cbegin() const;
    ConstStrBlobPtr cend() const;

private:
    std::shared_ptr<std::vector<std::string>> _data;
    void check(size_type i, const std::string &msg) const;

    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;
};

#endif
