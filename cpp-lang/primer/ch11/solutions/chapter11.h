#ifndef CHAPTER11_H
#define CHAPTER11_H

#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <list>

// Globals

inline static void error(const std::string &msg)
{
    std::cout << msg << std::endl;
    exit(1);
}

/*
 * Exercise 11.3 - 11.4:
 * Write your own version of the word-counting program.
 * Extend your program to ignore case and punctuation. For
 * example, “example.” “example,” and “Example” should all increment the same
 * counter.
 */

void read_word_count(const std::string &file_name,
		     std::map<std::string, size_t> &dest);
void sol_11_3_4();

/*
 * Exercise 11.7:
 * Define a map for which the key is the family’s last name and
 * the value is a vector of the children’s names. Write code to add new
 * families and to add new children to an existing family.
 */

void add_family(const std::string &family_last_name,
		const std::vector<std::string> &children,
		std::map<std::string, std::vector<std::string>> &family);
void add_child(const std::string &family_last_name,
	       const std::string &child_name,
	       std::map<std::string, std::vector<std::string>> &family);
void sol_11_7();

/*
 * Exercise 11.8:
 * Write a program that stores the excluded words in a vector
 * instead of in a set. What are the advantages to using a set?
 */

void read_word_count_2(const std::string &file_name,
		       std::map<std::string, size_t> &dest);
void sol_11_8();


/*
 * Exercise 11.9:
 * Define a map that associates words with a list of line
 * numbers on which the word might occur.
 */

void read_words_occurrence(const std::string &file_name,
			   std::map<std::string, std::list<int>> &words_occur);
void sol_11_9();

/*
 * Exercise 11.12:
 * Write a program to read a sequence of strings and ints,
 * storing each into a pair. Store the pairs in a vector.
 */

void read_pairs(const std::string &file_name,
		std::vector<std::pair<std::string, int>> &pairs);
void sol_11_12();

/*
 * Exercise 11.14:
 * Extend the map of children to their family name that you
 * wrote for the exercises in § 11.2.1 (p. 424) by having the vector store a
 * pair that holds a child’s name and birthday.
 */

void add_family(const std::string &,
		const std::vector<std::pair<std::string, std::string>> &,
		std::map<std::string,
		    std::vector<std::pair<std::string, std::string>>> &);
void add_child(const std::string &,
	       const std::pair<std::string, std::string> &,
	       std::map<std::string,
	           std::vector<std::pair<std::string, std::string>>> &);
void add_child(const std::string &, const std::string &, const std::string &,
	       std::map<std::string,
	           std::vector<std::pair<std::string, std::string>>> &);

/*
 * Exercise 11.18:
 * Write the type of map_it from the loop on page 430
 * without using auto or decltype.
 */

void sol_11_18();

/*
 * Exercise 11.20:
 * Rewrite the word-counting program from § 11.1 (p. 421) to
 * use insert instead of subscripting. Which program do you think is easier to
 * write and read? Explain your reasoning.
 */

void sol_11_20();

/*
 * Exercise 11.22:
 * Given a map<string, vector<int>>, write the types
 * used as an argument and as the return value for the version of insert that
 * inserts one element.
 */

void sol_11_22();

/*
 * Exercise 11.28:
 * Define and initialize a variable to hold the result of calling
 * find on a map from string to vector of int.
 */

void sol_11_28();

/*
 * Exercise 11.32:
 * Using the multimap from the previous exercise, write a
 * program to print the list of authors and their works alphabetically.
 */

void sol_11_32();

/*
 * Exercise 11.38:
 * Rewrite the word-counting (§ 11.1, p. 421) and word-
 * transformation (§ 11.3.6, p. 440) programs to use an unordered_map.
 */

void sol_11_38_1();
void sol_11_38_2();

#endif
