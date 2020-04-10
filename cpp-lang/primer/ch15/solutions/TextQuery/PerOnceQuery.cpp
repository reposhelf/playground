#include "PerOnceQuery.h"

#include <numeric>
#include <sstream>

QueryResult PerOnceQuery::eval(const TextQuery &t) const
{
    auto result = t.query(mQueryWord);
    auto lines = std::make_shared<std::set<line_no>>(result.begin(), result.end());
    if (lines->size() > 1)
        return result;

    if (lines->size() == 0)
        return QueryResult(rep(), nullptr, nullptr);

    std::vector<std::string> vText = *result.get_file();
    std::string text = std::accumulate(vText.begin(), vText.end(), std::string());

    std::vector<std::string> new_file;
    std::string sentence;
    std::istringstream in(text);
    while (std::getline(in, sentence, '.'))
    {
        if (!sentence.empty())
        {
            if (sentence.find(mQueryWord) != std::string::npos)
            {
                sentence.push_back('.');
                new_file.push_back(sentence);
                break;
            }
        }
    }

    std::shared_ptr<std::set<line_no>> ret_lines(new std::set<line_no>{0});
    auto ret_file = std::make_shared<std::vector<std::string>>(new_file.begin(), new_file.end());

    return QueryResult(rep(), ret_lines, ret_file);
}
