#ifndef BINARYQUERY_H
#define BINARYQUERY_H

#include "QueryBase.h"
#include "Query.h"

class BinaryQuery : public QueryBase
{
protected:
    BinaryQuery(const Query &l, const Query &r, const std::string &s)
        : lhs(l), rhs(r), opSym(s) { std::cout << "BinaryQuery(Query,Query,std::string)" << std::endl; }
    std::string rep() const;
    Query lhs, rhs;
    std::string opSym;
};

#endif
