#ifndef QUERYBASE_H
#define QUERYBASE_H

#include "TextQuery.h"
#include "QueryResult.h"

class QueryBase
{
    friend class Query;

protected:
    using line_no = TextQuery::line_no;
    QueryBase() { std::cout << "QueryBase()" << std::endl; }
    virtual ~QueryBase() = default;

private:
    virtual QueryResult eval(const TextQuery&) const = 0;
    virtual std::string rep() const = 0;
};

#endif
