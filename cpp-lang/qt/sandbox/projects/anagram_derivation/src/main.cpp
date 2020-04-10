#include <iostream>
#include <string>

#include "anagramsmanager.h"

int main(int argc, char **argv)
{
    AnagramsManager anagrams(argc, argv);

    char user_response;
    do
    {
        std::cout << "Enter 3-letters word: ";
        std::string word;
        std::getline(std::cin, word);

        if (word.size() != 3)
            std::cout << "Incorrect word size" << std::endl;
        else
            std::cout << anagrams.result(word);

        std::cout << "\nDo you want to continue? [y/n] ";
        std::cin >> user_response;
        std::cin.ignore();
    }
    while (tolower(user_response) == 'y');

    return 0;
}
