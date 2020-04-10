#include "Query.h"

std::vector<Query> Query::history;

Query::Query(const std::string &s, OutputType ot)
    : q(nullptr)
{
    switch (ot)
    {
    case DefaultOutput:
        q = new WordQuery(s);
        break;
    case PerOnceOutput:
        q = new PerOnceQuery(s);
        break;
    default:
        q = new WordQuery(s);
    }
}

Query &Query::operator=(const Query &other)
{
    QueryBase *t = other.q->clone();
    delete q;
    q = t;
    return *this;
}
