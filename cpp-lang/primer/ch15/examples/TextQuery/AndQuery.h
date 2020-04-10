#ifndef ANDQUERY_H
#define ANDQUERY_H

#include "BinaryQuery.h"
#include "AndQuery.h"

class AndQuery : public BinaryQuery
{
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query &left, const Query &right)
        : BinaryQuery(left, right, "&") { std::cout << "AndQuery(Query,Query)" << std::endl; }
    QueryResult eval(const TextQuery&) const;
};

inline Query operator&(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<QueryBase>(new AndQuery(lhs, rhs));
}

#endif
