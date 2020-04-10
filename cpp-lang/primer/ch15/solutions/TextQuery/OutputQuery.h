#ifndef OUTPUTQUERY_H
#define OUTPUTQUERY_H

#include "QueryBase.h"

#include <string>

class OutputQuery : public QueryBase
{
protected:
    OutputQuery(const std::string &s): mQueryWord(s) {}
    std::string rep() const override { return mQueryWord; }
    std::string mQueryWord;
};

#endif
