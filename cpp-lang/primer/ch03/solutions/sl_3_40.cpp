/*
 * Exercise 3.40:
 * Write a program to define two character arrays initialized
 * from string literals. Now define a third character array to hold the
 * concatenation of the two arrays. Use strcpy and strcat to copy the two
 * arrays into the third.
 */
#include <iostream> 
using std::cout;
using std::endl;

#include <cstring>

int main()
{
    const char cc1[] = "Hello, ";
    const char cc2[] = "world!";
    char result[20];

    strcpy(result, cc1);
    strcat(result, cc2);

    cout << result << endl;

    return 0;
}
