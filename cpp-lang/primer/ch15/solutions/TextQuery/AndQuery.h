#ifndef ANDQUERY_H
#define ANDQUERY_H

#include "BinaryQuery.h"
#include "AndQuery.h"

class AndQuery : public BinaryQuery
{
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query &left, const Query &right)
        : BinaryQuery(left, right, "&") {}
    QueryResult eval(const TextQuery&) const override;
    AndQuery *clone() const & override { return new AndQuery(*this); }
};

inline Query operator&(const Query &lhs, const Query &rhs)
{
    return Query(new AndQuery(lhs, rhs));
}

#endif
