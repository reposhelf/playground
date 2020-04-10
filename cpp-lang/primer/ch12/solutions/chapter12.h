#ifndef CHAPTER12_H
#define CHAPTER12_H

#include <vector>
#include <iostream>
#include <memory>

/*
 * Exercise 12.6:
 * Write a function that returns a dynamically allocated vector
 * of ints. Pass that vector to another function that reads the standard input
 * to give values to the elements. Pass the vector to another function to print
 * the values that were read. Remember to delete the vector at the
 * appropriate time.
 */

std::vector<int> *createVectorOfInt();
void readVectorOfInt(std::istream &in, std::vector<int>* &vi);
void printVectorOfInt(std::ostream &out, std::vector<int>* &vi);

/*
 * Exercise 12.7:
 * Redo the previous exercise (12.6), this time using shared_ptr.
 */

std::shared_ptr<std::vector<int>> createSharedPtrVectorOfInt();
void readVectorOfInt(std::istream &in, std::shared_ptr<std::vector<int>> &vi);
void printVectorOfInt(std::ostream &out, std::shared_ptr<std::vector<int>> &vi);

/*
 * Exersice 12.17:
 * Write your own version of a function that uses a
 * shared_ptr to manage a connection.
 */

struct destination
{
    const char *address;
};

struct connection
{
    destination *dest;
};

connection connect(destination *dest);
void disconnect(connection *c);

/*
 * Exercise 12.23:
 * Write a program to concatenate two string literals, putting
 * the result in a dynamically allocated array of char. Write a program to
 * concatenate two library strings that have the same value as the literals
 * used in the first program.
 */

void sol_12_23_1();
void sol_12_23_2();

/*
 * Exercise 12.24:
 * Write a program that reads a string from the standard input
 * into a dynamically allocated character array. Describe how your program
 * handles varying size inputs. Test your program by giving it a string of data
 * that is longer than the array size you’ve allocated.
 */

void sol_12_24();

/*
 * Exercise 12.26:
 * Rewrite the exercise 12.23 using an allocator.
 */

void sol_12_26();

/*
 * Exercise 12.28:
 * Write a program to implement text queries without defining
 * classes to manage the data. Your program should take a file and interact
 * with a user to query for words in that file. Use vector, map, and set
 * containers to hold the data for the file and to generate the results for the
 * queries.
 */

void sol_12_28();

#endif
