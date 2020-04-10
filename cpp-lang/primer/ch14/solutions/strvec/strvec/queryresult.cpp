#include "queryresult.h"

QueryResult::QueryResult(const std::string &s,
            std::shared_ptr<std::set<TextQuery::line_no>> p,
            std::shared_ptr<StrVec> f)
    : sought(s), lines(p), file(f)
{
}
