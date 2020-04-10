#ifndef BINARYQUERY_H
#define BINARYQUERY_H

#include "QueryBase.h"
#include "Query.h"

class BinaryQuery : public QueryBase
{
protected:
    BinaryQuery(const Query &l, const Query &r, const std::string &s)
        : lhs(l), rhs(r), opSym(s) {}
    std::string rep() const override;
    Query lhs, rhs;
    std::string opSym;
};

#endif
