/*
 * Exercise 10.33:
 * Write a program that takes the names of an input file and
 * two output files. The input file should hold integers. Using an
 * istream_iterator read the input file. Using ostream_iterators, write
 * the odd numbers into the first output file. Each value should be followed by a
 * space. Write the even numbers into the second file. Each of these values
 * should be placed on a separate line.
 */

#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ifstream inFile("sol_10_33_data");
    istream_iterator<int> inIterator(inFile), eof;

    vector<int> numbers(inIterator, eof);
    auto it = partition(numbers.begin(), numbers.end(), [] (int i) { return (i % 2) != 0; });
    sort(numbers.begin(), it);
    sort(it, numbers.end());

    ofstream oddFile("sol_10_33_odd");
    ostream_iterator<int> outOdd(oddFile, " ");
    copy(numbers.begin(), it, outOdd);

    ofstream evenFile("sol_10_33_even");
    ostream_iterator<int> outEven(evenFile, "\n");
    copy(it, numbers.end(), outEven);

    return 0;
}