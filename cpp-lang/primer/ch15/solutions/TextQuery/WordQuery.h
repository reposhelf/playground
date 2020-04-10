#ifndef WORDQUERY_H
#define WORDQUERY_H

#include "OutputQuery.h"

#include <string>

class WordQuery : public OutputQuery
{
    friend class Query;
    WordQuery(const std::string &s): OutputQuery(s) {}
    QueryResult eval(const TextQuery &t) const override { return t.query(mQueryWord); }
    WordQuery *clone() const & override { return new WordQuery(*this); }
};

#endif
