#ifndef CWORDLIST_H
#define CWORDLIST_H

#include <string>

struct wordstruct;
class CWordList
{
public:
    CWordList();
    ~CWordList();
    void insert(const std::string&);
    void print() const;
    void fprint(const std::string &filename) const;

private:
    bool exist(const std::string&) const;
    void insert_alphabetical(wordstruct**, const std::string&);

    wordstruct *_words;
};

#endif // CWORDLIST_H
