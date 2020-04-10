#ifndef WORDQUERY_H
#define WORDQUERY_H

#include "QueryBase.h"

#include <string>

class WordQuery : public QueryBase
{
    friend class Query;
    WordQuery(const std::string &s): mQueryWord(s) { std::cout << "WordQuery(std::string)" << std::endl; }
    QueryResult eval(const TextQuery &t) const { return t.query(mQueryWord); }
    std::string rep() const { std::cout << "WordQuery::rep()" << std::endl; return mQueryWord; }
    std::string mQueryWord;
};

#endif
