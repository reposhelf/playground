#include "cwordlist.h"

#include <iostream>
#include <iomanip>

using namespace std;

struct wordstruct
{
    string word;
    short count = 1;
    wordstruct *next = nullptr;
};

CWordList::CWordList()
    : _words(nullptr)
{
}

CWordList::~CWordList()
{
    while (_words) {
        wordstruct *t = _words;
        _words = _words->next;
        delete t;
    }
}

void CWordList::insert(const std::string &w)
{
    if (!exist(w))
        insert_alphabetical(&_words, w);
}

void CWordList::print() const
{
    for (wordstruct *i = _words; i != nullptr; i = i->next)
        cout << setw(20) << left << i->word << i->count << endl;
}

#include <fstream>
void CWordList::fprint(const string &filename) const
{
    ofstream fout(filename, std::ios::app);
    for (wordstruct *i = _words; i != nullptr; i = i->next)
        fout << i->word << ' ' << i->count << endl;
}

bool CWordList::exist(const string &w) const
{
    for (wordstruct *i = _words; i != nullptr; i = i->next) {
        if (i->word == w) {
            ++i->count;
            return true;
        }
    }
    return false;
}

void CWordList::insert_alphabetical(wordstruct **words, const string &w)
{
    wordstruct *new_word = new wordstruct;
    new_word->word = w;

    for (/* empty */; *words != nullptr; words = &(*words)->next) {
        if (new_word->word < (*words)->word)
            break;
    }

    new_word->next = *words;
    *words = new_word;
}
