#ifndef PERONCEQUERY_H
#define PERONCEQUERY_H

#include "OutputQuery.h"

class PerOnceQuery : public OutputQuery
{
    friend class Query;
    PerOnceQuery(const std::string &s): OutputQuery(s) {}
    QueryResult eval(const TextQuery&) const override;
    std::string rep() const override { return "(Per Once): " + mQueryWord; }
    PerOnceQuery *clone() const & override { return new PerOnceQuery(*this); }
};

#endif
