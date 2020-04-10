#include "BinaryQuery.h"

std::string BinaryQuery::rep() const
{
    return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
}
