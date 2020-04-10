#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include "strvec.h"

#include <vector>
#include <string>
#include <memory>
#include <map>
#include <set>
#include <fstream>

class QueryResult;
class TextQuery
{
public:
    using line_no = std::vector<std::string>::size_type;
    TextQuery(std::ifstream &);
    QueryResult query(const std::string &) const;

private:
    std::shared_ptr<StrVec> file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

#endif
