#ifndef ORQUERY_H
#define ORQUERY_H

#include "BinaryQuery.h"
#include "Query.h"

class OrQuery : public BinaryQuery
{
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query &left, const Query &right)
        : BinaryQuery(left, right, "|") {}
    QueryResult eval(const TextQuery&) const override;
    OrQuery *clone() const & override { return new OrQuery(*this); }
};

inline Query operator|(const Query &lhs, const Query &rhs)
{
    return Query(new OrQuery(lhs, rhs));
}

#endif
