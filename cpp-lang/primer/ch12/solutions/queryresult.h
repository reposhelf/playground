#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include <iostream>
#include <memory>
#include <string>
#include <map>

class QueryResult
{
public:
    QueryResult(size_t word_count,
                const std::string &word,
                std::shared_ptr<std::map<size_t, std::string>> lines_ptr);

private:
    size_t _word_count;
    std::string _word;
    std::shared_ptr<std::map<size_t, std::string>> _lines_ptr;

    friend std::ostream &operator<<(std::ostream &os, const QueryResult &qr);
};

inline std::ostream &operator<<(std::ostream &os, const QueryResult &qr)
{
    os << qr._word << " occurs " << qr._word_count << " times" << std::endl;
    for (const auto &p : *(qr._lines_ptr)) {
        os << std::string(4, ' ');
        os << "(line " << p.first << ") ";
        os << p.second << std::endl;
    }
    return os;
}

#endif
