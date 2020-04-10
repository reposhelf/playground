#ifndef NOTQUERY_H
#define NOTQUERY_H

#include "QueryBase.h"
#include "Query.h"

class NotQuery : public QueryBase
{
    friend Query operator~(const Query&);
    NotQuery(const Query &q): query(q) { std::cout << "NotQuery(Query)" << std::endl; }
    QueryResult eval(const TextQuery&) const;
    std::string rep() const { std::cout << "NotQuery::rep()" << std::endl; return "~(" + query.rep() + ")"; }
    Query query;
};

inline Query operator~(const Query &operand)
{
    return std::shared_ptr<QueryBase>(new NotQuery(operand));
}

#endif
