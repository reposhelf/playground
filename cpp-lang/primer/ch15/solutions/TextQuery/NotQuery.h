#ifndef NOTQUERY_H
#define NOTQUERY_H

#include "QueryBase.h"
#include "Query.h"

class NotQuery : public QueryBase
{
    friend Query operator~(const Query&);
    NotQuery(const Query &q): query(q) {}
    QueryResult eval(const TextQuery&) const override;
    std::string rep() const override { return "~(" + query.rep() + ")"; }
    NotQuery *clone() const & override { return new NotQuery(*this); }
    Query query;
};

inline Query operator~(const Query &operand)
{
    return Query(new NotQuery(operand));
}

#endif
