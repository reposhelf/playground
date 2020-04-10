#include "anagramsmanager.h"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>

namespace {
bool is_anagram(const std::string &dict_word, const std::string &word,
                char &extra_char)
{
    bool found = false;
    for (const auto &c : dict_word)
    {
        int diff = std::count(dict_word.cbegin(), dict_word.cend(), c)
                - std::count(word.cbegin(), word.cend(), c);

        if (diff == 0)
            continue;

        if (diff == 1)
        {
            if (found && extra_char != c)
                return false;

            found = true;
            extra_char = c;
            continue;
        }

        return false;
    }
    return true;
}

std::string str_tolower(std::string str)
{
    std::transform(str.begin(), str.end(), str.begin(),
                   [](unsigned char c){ return tolower(c); });
    return str;
}

std::vector<std::string> DefaultDictionary = {
    "ail", "desk", "sail", "nails", "table", "aliens", "engine", "tennis"};

} // namespace

AnagramsManager::AnagramsManager(int argc, char **argv)
{
    if (argc > 1)
    {
        std::ifstream file(argv[1]);
        if (!file.is_open())
        {
            std::cout << "Cannot open specifeid dictionary."
                      << std::endl
                      << "Default dictionary will be used."
                      << std::endl;
            init_default_dictionary();
        }
        else
        {
            load_specified_dictionary(file);
        }
    }
    else
    {
        std::cout << "Default dictionary will be used." << std::endl;
        init_default_dictionary();
    }
}

std::string AnagramsManager::result(const std::string &word)
{
    search_anagrams(word, word);

    std::string result;
    for (const auto &s : results_)
        result += s + "\n";

    results_.clear();

    return result;
}

void AnagramsManager::fill_dictionary(const std::vector<std::string> &words)
{
    dictionary_.resize(8 * 4);

    for (const auto &word : words)
    {
        assert(word.size() < dictionary_.size());
        dictionary_[word.size()].push_back(str_tolower(word));
    }
}

void AnagramsManager::init_default_dictionary()
{
    fill_dictionary(DefaultDictionary);
}

void AnagramsManager::load_specified_dictionary(std::ifstream &file)
{
    std::istream_iterator<std::string> begin(file), end;
    std::vector<std::string> words(begin, end);

    fill_dictionary(words);
}

void AnagramsManager::search_anagrams(const std::string &word, std::string level_result)
{
    for (const auto &w : dictionary_[word.size() + 1])
    {
        char c;
        if (is_anagram(w, word, c))
            search_anagrams(w, level_result + "+" + std::string(1, c) + "=" + w);
    }

    add_result(level_result);
}

void AnagramsManager::add_result(const std::string &new_result)
{
    if (results_.empty())
    {
        results_.insert(new_result);
    }
    else
    {
        std::string item = *(results_.cbegin());
        int diff = std::count(item.cbegin(), item.cend(), '=')
                - std::count(new_result.cbegin(), new_result.cend(), '=');
        if (diff == 0)
        {
            results_.insert(new_result);
        }
        else if (diff < 0)
        {
            results_.clear();
            results_.insert(new_result);
        }
    }
}

