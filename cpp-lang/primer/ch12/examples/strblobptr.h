#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H

#include <memory>
#include <vector>
#include <string>

class StrBlob;
class StrBlobPtr
{
public:
    StrBlobPtr();
    StrBlobPtr(StrBlob &sb, std::size_t sz = 0);
    
    std::string &deref() const;
    StrBlobPtr &incr();

private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;

    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};

#endif
