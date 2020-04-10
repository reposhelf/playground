#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include "queryresult.h"

#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <memory>

class TextQuery
{
public:
    explicit TextQuery(std::ifstream &input);
    QueryResult query(const std::string &word) const;

private:
    std::vector<std::string> _text;
    std::shared_ptr<std::map<size_t, std::string>> _lines_ptr;
};

#endif
