#ifndef ORQUERY_H
#define ORQUERY_H

#include "BinaryQuery.h"
#include "Query.h"

class OrQuery : public BinaryQuery
{
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query &left, const Query &right)
        : BinaryQuery(left, right, "|") { std::cout << "OrQuery(Query,Query)" << std::endl; }
    QueryResult eval(const TextQuery&) const;
};

inline Query operator|(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<QueryBase>(new OrQuery(lhs, rhs));
}

#endif
