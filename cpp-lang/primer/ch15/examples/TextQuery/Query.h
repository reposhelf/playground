#ifndef QUERY_H
#define QUERY_H

#include "QueryResult.h"
#include "WordQuery.h"

class TextQuery;
class QueryBase;
class Query
{
    friend Query operator~(const Query&);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);

public:
    Query(const std::string &s): q(new WordQuery(s)) { std::cout << "Query(std::string)" << std::endl; }

    QueryResult eval(const TextQuery &t) const { return q->eval(t); }
    std::string rep() const { std::cout << "Query::rep()" << std::endl; return q->rep(); }

private:
    Query(std::shared_ptr<QueryBase> query): q(query) { std::cout << "Query(std::shared_ptr<>)" << std::endl; }
    std::shared_ptr<QueryBase> q;
};

inline std::ostream &operator<<(std::ostream &os, const Query &query)
{
    return os << query.rep();
}

#endif
