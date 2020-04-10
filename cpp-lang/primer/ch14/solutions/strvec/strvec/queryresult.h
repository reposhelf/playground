#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include "strvec.h"
#include "textquery.h"

#include <iostream>
#include <string>
#include <memory>

class QueryResult
{
public:
    QueryResult(const std::string &s,
                std::shared_ptr<std::set<TextQuery::line_no>> p,
                std::shared_ptr<StrVec> f);

private:
    std::string sought;
    std::shared_ptr<std::set<TextQuery::line_no>> lines;
    std::shared_ptr<StrVec> file;

    friend std::ostream &operator<<(std::ostream &, const QueryResult &);
};

inline std::string make_plural(TextQuery::line_no count, const std::string &word, const std::string &end)
{
    return count > 1 ? word + end : word;
}

inline std::ostream &operator<<(std::ostream &os, const QueryResult &qr)
{
    os << qr.sought << " occurs " << qr.lines->size() << " "
       << make_plural(qr.lines->size(), "time", "s") << std::endl;

    for (auto num : *qr.lines) {
        os << "\t(line" << num + 1 << ") "
           << *(qr.file->begin() + num) << std::endl;
    }

    return os;
}

#endif
