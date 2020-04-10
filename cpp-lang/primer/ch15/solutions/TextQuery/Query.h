#ifndef QUERY_H
#define QUERY_H

#include "QueryResult.h"
#include "WordQuery.h"
#include "PerOnceQuery.h"

class TextQuery;
class QueryBase;
class Query
{
    friend Query operator~(const Query&);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);

public:
    enum OutputType
    {
        DefaultOutput,
        PerOnceOutput
    };

    Query(const std::string &s, OutputType ot = DefaultOutput);
    Query(const Query &other): q(other.q->clone()) {}
    Query &operator=(const Query &other);
    ~Query() { delete q; }

    QueryResult eval(const TextQuery &t) const { return q->eval(t); }
    std::string rep() const { return q->rep(); }
    void addToHistory() const { history.push_back(*this); }

    static Query fromHistory(size_t pos) { return history.at(pos); }

private:
    Query(QueryBase *query): q(query) {}
    QueryBase *q;
    static std::vector<Query> history;
};

inline std::ostream &operator<<(std::ostream &os, const Query &query)
{
    return os << query.rep();
}

#endif
