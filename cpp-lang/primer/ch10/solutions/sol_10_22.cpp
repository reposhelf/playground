/*
 * Exercise 10.22:
 * Rewrite the program to count words of size 6 or less using functions in place of
 * the lambdas.
 */

#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <functional>

using namespace std::placeholders;

void error(const char *msg)
{
    std::cout << msg << std::endl;
    exit(1);
}

void elimDups(std::vector<std::string> &v)
{
    std::sort(v.begin(), v.end());
    auto unique_end = std::unique(v.begin(), v.end());
    v.erase(unique_end, v.end());
}

std::string make_plural(size_t count, const std::string &word, const std::string &ending)
{
    return (count > 1) ? word + ending : word;
}

bool isShorter(const std::string &s1, const std::string &s2)
{
    return s1.size() < s2.size();
}

void print(const std::string &s)
{
    std::cout << s << " ";
}

bool check_size(const std::string &s, std::string::size_type sz)
{
    return s.size() >= sz;
}

void biggies(std::vector<std::string> &words, std::vector<std::string>::size_type sz)
{
    elimDups(words);
    std::stable_sort(words.begin(), words.end(), isShorter);
    auto it = std::find_if(words.begin(), words.end(), std::bind(check_size, _1, sz));

    auto count = words.end() - it;
    std::cout << count << " " << make_plural(count, "word", "s")
              << " of length " << sz << " or longer" << std::endl;

    std::for_each(it, words.end(), print);
    std::cout << std::endl;
}

int main()
{
    std::ifstream in("sol_10_9_data");
    if (!in.is_open())
        error("Failed to open file.");

    std::string word;
    std::vector<std::string> words;
    while (in >> word)
        words.push_back(word);

    biggies(words, 6);

    return 0;
}