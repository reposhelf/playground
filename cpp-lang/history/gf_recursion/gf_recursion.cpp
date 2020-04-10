#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
 
using namespace std;
 
// Problem 1
//
// Write a function that takes a string and returns true if that string is a palindrome and false
// otherwise.
 
bool isPalindrome(const string& input)
{
    if (input.size() <= 1)
        return true;
 
    if (input.front() != input.back())
        return false;
 
    string newinput;
    copy(input.begin() + 1, input.end() - 1, back_inserter(newinput));
 
    return isPalindrome(newinput);
}
 
 
// Problem 2
//
// Write a function that takes an integer and returns the sum of its digits.For this function, you
// will have to make clever use of the / and % operators!
 
int digitSum(int input)
{
    return input != 0 ? input % 10 + digitSum(input / 10) : 0;
}
 
// Problem 3
//
// You are standing at the base of a staircase.At each step as you climb the staircase, you have
// the option of taking a small stride(one stair) or a large stride(two stairs - assuming there are
// at least two stairs remaining).Given that a staircase has X number of stairs, how many ways are
// there to climb the staircase using different combinations of small and large strides ? Write a
// function that takes a total number of stairs in the staircase and returns the number of ways to
// climb it.If the staircase has three steps, for example, there are three ways to climb it(three
// small strides, or a large stride followed by a small stride, or a small stride followed by a
// large stride).
 
int fibonacci(int value)
{
    if (value < 1)
        return 0;
 
    if (value == 1)
        return 1;
 
    return fibonacci(value - 1) + fibonacci(value - 2);
}
 
int waysToClimb(int numStairs)
{
    return fibonacci(numStairs + 1);
}
 
int main()
{
    cout << isPalindrome("stats") << endl;
    cout << digitSum(1259) << endl;
    cout << waysToClimb(4) << endl;
 
    return 0;
}
