#include "BinaryQuery.h"

std::string BinaryQuery::rep() const
{
    std::cout << "BinaryQuery::rep()" << std::endl;

    return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
}
