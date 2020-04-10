/*
 * Anagram derivation algorithm:
 *
 * 1. Call a function for anagram searching with start word;
 * 2. The function starts searching anagrams in set of words which have size by 1 letter greater than start word;
 * 3. If the right word was found, update results of searching and do step 1 and 2 for this new word;
 *
 * Words checking:
 *
 * If first word has size by 1 letter greater than second word and second word is substring of first word, it's
 * mean that words can be added to common results.
 *
 * Note:
 * All dictionary words holds in vector<vector<string>> where word.size() is index of vector where this word will be stored;
 */
#ifndef ANAGRAMSMANAGER_H
#define ANAGRAMSMANAGER_H

#include <fstream>
#include <string>
#include <vector>
#include <set>

class AnagramsManager
{
public:
    AnagramsManager(int argc, char **argv);

    std::string result(const std::string &word);

private:
    void fill_dictionary(const std::vector<std::string> &words);
    void init_default_dictionary();
    void load_specified_dictionary(std::ifstream &file);
    void search_anagrams(const std::string &word, std::string level_result);
    void add_result(const std::string &new_result);

    std::vector<std::vector<std::string>> dictionary_;
    std::set<std::string> results_;
};

#endif // ANAGRAMSMANAGER_H
