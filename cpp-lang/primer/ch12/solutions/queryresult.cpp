#include "queryresult.h"

using namespace std;

QueryResult::QueryResult(size_t word_count,
                         const string &word,
                         shared_ptr<map<size_t, string>> lines_ptr)
    : _word_count(word_count),
      _word(word),
      _lines_ptr(lines_ptr)
{}
