#include "AndQuery.h"

#include <algorithm>
#include <iterator>

QueryResult AndQuery::eval(const TextQuery &text) const
{
    auto right = rhs.eval(text), left = lhs.eval(text);
    auto ret_lines = std::make_shared<std::set<line_no>>();
    set_intersection(left.begin(), left.end(),
            right.begin(), right.end(),
            std::inserter(*ret_lines, ret_lines->begin()));
    return QueryResult(rep(), ret_lines, left.get_file());
}