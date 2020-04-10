#include "kyu_8.h"


#include <algorithm>
#include <bitset>
#include <cmath>
#include <iterator>
#include <numeric>
#include <map>


// [8kyu] Opposite number
//
// Very simple, given a number, find its opposite.
// Examples:
//   1: -1
//   14: -14
//   -34: 34
//
// But can you do it in 1 line of code and without any conditionals?
int opposite(int number) {
    return -number;
}


// [8kyu] MakeUpperCase
//
// Write function makeUpperCase.
std::string makeUpperCase(const std::string & inputStr) {
    std::string outputStr = inputStr;
    std::transform(outputStr.begin(), outputStr.end(), outputStr.begin(), ::toupper);
    return outputStr;
}


// [8kyu] Rock Paper Scissors!
//
// Let's play! You have to return which player won! In case of a draw return Draw!.
// Examples:
//   rps('scissors', 'paper') // Player 1 won!
//   rps('scissors', 'rock') // Player 2 won!
//   rps('paper', 'paper') // Draw!
std::string rsp(const std::string & firstPlayerChoice, const std::string & secondPlayerChoice) {
    if (firstPlayerChoice == secondPlayerChoice) {
        return "Draw!";
    }

    if ((firstPlayerChoice == "scissors" && secondPlayerChoice == "paper")
        || (firstPlayerChoice == "paper" && secondPlayerChoice == "rock")
        || (firstPlayerChoice == "rock" && secondPlayerChoice == "scissors")) {
        return "Player 1 won!";
    }

    return "Player 2 won!";
}


// [8kyu] The 'if' function
//
// Who likes keywords ? Nobody likes keywords, so why use them ?
// You know what keyword I use too much ? if!We should make a function called _if, with its
// arguments as a logical test and two functions / lambdas where the first function is executed
// if the boolean is true, and the second if it's false, like an if/else statement, so that we
// don't have to mess around with those nasty keywords!
// Even so, It should support truthy / falsy types just like the keyword.
//
// Example :
//   void TheTrue() { std::cout << "true" }
//   void TheFalse() { std::cout << "false" }
//   _if(true, TheTrue, TheFalse);
//   // Logs 'true' to the console.
void _if(bool value, std::function<void(void)> func1, std::function<void(void)> func2) {
    value ? func1() : func2();
}


// [8kyu] A function within a function
//
// Given an input n, write a function always that returns a function which returns n.
//
// function<int (void)> three = always(3);
// three(); // returns 3
std::function<int(void)> always(int number) {
    return [number]() { return number; };
}


// [8kyu] Square(n) Sum
//
// Complete the squareSum method so that it squares each number passed into it and then
// sums the results together.
//
// For example:
// squareSum({1, 2, 2}); // should return 9
int squareSum(const std::vector<int > &numbers) {
    return std::accumulate(numbers.begin(), numbers.end(), 0,
        [](int sum, int curr) {return sum + curr * curr; });
}


// [8kyu] Find n'th Digit of a Number
//
// The function findDigit takes two numbers as input, num and nth.
// It outputs the nth digit of num (counting from right to left).
//
// Note:
// * If num is negative, ignore its sign and treat it as a positive value.
// * If nth is not positive, return -1.
// * Keep in mind that 42 = 00042. This means that findDigit(42, 5) would return 0.
//
// Examples:
// findDigit(5673, 4)     returns 5
// findDigit(129, 2)      returns 2
// findDigit(-2825, 3)    returns 8
// findDigit(-456, 4)     returns 0
// findDigit(0, 20)       returns 0
// findDigit(65, 0)       returns - 1
// findDigit(24, -8)      returns - 1
int findDigit(int num, int nth) {
    if (nth <= 0)
        return -1;

    int bottom = std::pow(10, nth - 1);
    int digit = num / bottom % 10;
    return digit < 0 ? -digit : digit;
}


// [8kyu] I love you, a little , a lot, passionately ... not at all
// Who remembers back to their time in the schoolyard, when girls would take
// a flower and tear its petals, saying each of the following phrases each time
// a petal was torn :
// * I love you
// * a little
// * a lot
// * passionately
// * madly
// * not at all
//
// When the last petal was torn there were cries of excitement, dreams, surging
// thoughts and emotions.
// Your goal in this kata is to determine which phrase the girls would say for
// a flower of a given number of petals, where nb_petals > 0.
std::string howMuchILoveYou(int amountPetals) {
    static const std::string variants[] = { "I love you", "a little", "a lot",
        "passionately", "madly", "not at all" };

    return variants[(amountPetals - 1) % (sizeof(variants) / sizeof(*variants))];
}


// [8kyu] Evil or Odious
// The number n is Evil if it has an even number of 1's in its binary expansion.
// First ten : 3, 5, 6, 9, 10, 12, 15, 17, 18, 20
//
// The number n is Odious if it has an odd number of 1's in its binary expansion.
// First ten : 1, 2, 4, 7, 8, 11, 13, 14, 16, 19
//
// You have to write a function that determine if a number is Evil of Odious,
// function should return "It's Evil!" in case of evil number and "It's Odious!"
// in case of odious number.
std::string evil(int n) {
    std::bitset<32> bits(n);
    return bits.count() & 0x1 ? "It's Odious!" : "It's Evil!";
}


// [8kyu] Invert values
// Given a set of numbers, return the additive inverse of each. Each positive
// becomes negatives, and the negatives become positives.
std::vector<int> invert(std::vector<int> values) {
    std::transform(values.begin(), values.end(), values.begin(),
        std::negate<int>());
    return values;
}


// [8kyu] Do I get a bonus?
//
// It's bonus time in the big city! The fatcats are rubbing their paws in
// anticipation... but who is going to make the most money?
//
// Build a function that takes in two arguments(salary, bonus).Salary will be an integer,
// and bonus a boolean.
//
// If bonus is true, the salary should be multiplied by 10. If bonus is false, the fatcat
// did not make enough money and must receive only his stated salary.
//
// Return the total figure the individual will receive as a string prefixed with '$'.
std::string bonusTime(int salary, bool bonus) {
    return "$" + std::to_string(salary) + (bonus ? "0" : "");
}


// [8kyu] Pythagorean Triple
//
// Given an array of 3 integers a, b and c, determine if they form a pythagorean triple.
//
// A pythagorean triple is formed when :
// c^2 = a^2 + b^2
// where c is the largest value of a, b, c.
//
// For example : a = 3, b = 4, c = 5 forms a pythagorean triple, because 5^2 = 3^2 + 4^2
bool pythagoreanTriple(const int a, const int b, const int c) {
    return std::pow(a, 2) + std::pow(b, 2) == std::pow(c, 2)
        || std::pow(b, 2) + std::pow(c, 2) == std::pow(a, 2)
        || std::pow(c, 2) + std::pow(a, 2) == std::pow(b, 2);
}


// [8kyu] Remove String Spaces
//
// Simple, remove the spaces from the string, then return the resultant string.
std::string noSpace(std::string x) {
    x.erase(std::remove_if(x.begin(), x.end(), isspace), x.end());
    return x;
}


// [8kyu] Counting sheep...
//
// Consider an array of sheep where some sheep may be missing from their place.
// We need a function that counts the number of sheep present in the array (true means present).
int countSheep(const std::vector<bool>& arr) {
    return std::count(arr.begin(), arr.end(), true);
}


// [8kyu] Pole Vault Starting Marks
// For a pole vaulter, it is very important to begin the approach run at the best possible
// starting mark.This is affected by numerous factors and requires fine - tuning in practice.
// But there is a guideline that will help a beginning vaulter start at approximately the right
// location for the so - called "three-step approach," based on the vaulter's body height.
//
// This guideline was taught to me in feet and inches, but due to the international nature of
// Codewars, I am creating this kata to use metric units instead.
//
// You are given the following two guidelines to begin with : (1) A vaulter with a height of 1.52
// meters should start at 9.45 meters on the runway. (2) A vaulter with a height of 1.83 meters
// should start at 10.67 meters on the runway.
//
// You will receive a vaulter's height in meters (which will always lie in a range between a
// minimum of 1.22 meters and a maximum of 2.13 meters). Your job is to return the best starting
// mark in meters, rounded to two decimal places.
//
// Hint : Based on the two guidelines given above, you will want to account for the change in
// starting mark per change in body height.This involves a linear relationship.
double startingMark(double height) {
    //assuming linear relationship between body height and starting mark
    double a = (10.67 - 9.45) / (1.83 - 1.52);
    double b = 10.67 - a * 1.83;
    return round(100 * (height * a + b)) / 100;
}


// [8kyu] Is it a palindrome?
//
// Write function isPalindrom that checks if a given string (case insensitive) is a palindrom.
bool isPalindrome(const std::string &str) {
    // faster but buggy
    //if (str.empty())
    //	return false;

    //int f = 0;
    //int b = str.length() - 1;

    //while (f < b)
    //{
    //	while ((f < b) && !isalpha(str[f]))
    //		++f;

    //	while ((f < b) && !isalpha(str[b]))
    //		--b;

    //	if (tolower(str[f]) != tolower(str[b]))
    //		return false;

    //	++f;
    //	--b;
    //}
    //return true;

    // slower but working
    std::string s = str;
    s.erase(std::remove_if(s.begin(), s.end(), [](unsigned char c) { return !isalpha(c); }),
        s.end());
    std::transform(s.begin(), s.end(), s.begin(), tolower);
    return (s == std::string(s.rbegin(), s.rend()));
}


// [8kyu] Volume of a Cuboid
//
// Bob needs a fast way to calculate the volume of a cuboid with three values:
// length, width and the height of the cuboid. Write a function to help Bob with this calculation.
double getVolumeOfCuboid(double length, double width, double height) {
    return length * width * height;
}


// [8kyu] Sum without highest and lowest number
//
// Sum all the numbers of the array(in F# and Haskell you get a list) except the highest and
// the lowest element(the value, not the index!).
// (The highest / lowest element is respectively only one element at each edge, even if there
// are more than one with the same value!)
//
// Example:
//    { 6, 2, 1, 8, 10 } => 16
//    { 1, 1, 11, 2, 3 } = > 6
//
int sum(std::vector<int> &&numbers) {
    if (numbers.empty() || numbers.size() == 1)
        return 0;
    std::sort(numbers.begin(), numbers.end());
    return std::accumulate(numbers.begin() + 1, numbers.end() - 1, 0);
}


// [8kyu] Count of positives / sum of negatives
//
// Given an array of integers.
//
// Return an array, where the first element is the count of positives numbers and the second
// element is sum of negative numbers.
//
// If the input array is empty or null, return an empty array.
//
// For example:
//    input vector<int> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -11, -12, -13, -14, -15}
//    return vector<int>  {10, -65}.
std::vector<int> countPositivesSumNegatives(std::vector<int> input) {
    if (input.empty())
        return std::vector<int>();
    auto isPositive = [](int x) { return !(x <= 0); };
    std::vector<int> res(2);
    // count of positive numbers
    res[0] = std::count_if(input.begin(), input.end(), isPositive);
    // sum of negative numbers
    std::sort(input.begin(), input.end());
    auto it = std::find_if(input.begin(), input.end(), isPositive);
    res[1] = std::accumulate(input.begin(), it, 0);

    return res;
}


// [8kyu] Sort and Star
//
// You will be given an vector of string(s). You must sort it alphabetically (case-sensitive!!)
// and then return the first value.
//
// The returned value must be a string, and have '***' between each of its letters.
std::string twoSort(const std::vector<std::string> &s) {
    std::string result = *(std::min_element(s.begin(), s.end()));
    for (size_t pos = result.size() - 1; pos != 0; --pos)
        result.insert(pos, "***");
    return result;
}


// [8kyu] Convert number to reversed array of digits
//
// Convert number to reversed array of digits
//
// Given a random number :
//    C++: unsigned long;
//
// You have to return the digits of this number within an array in reverse order.
// Example:
//     348597 => [7,9,5,8,4,3]
std::vector<int> digitize(unsigned long n) {
    std::vector<int> result;
    for (/*empty*/; n != 0; n /= 10)
        result.push_back(n % 10);
    return result;
}


// [8kyu] Hex to Decimal
//
// Write function hexToDec which converts hex number (given as a string) to decimal number.
int hexToDec(const std::string &hexString) {
    static std::map<char, int> HEX_TBL = {
        { '0', 0 }, { '1', 1 }, { '2', 2 }, { '3', 3 }, { '4', 4 },
        { '5', 5 }, { '6', 6 }, { '7', 7 }, { '8', 8 }, { '9', 9 },
        { 'A', 10 }, { 'a', 10 }, { 'B', 11 }, { 'b', 11 },
        { 'C', 12 }, { 'c', 12 }, { 'D', 13 }, { 'D', 13 },
        { 'E', 14 }, { 'e', 14 }, { 'F', 15 }, { 'f', 15 }
    };

    int result = 0;
    int index = 0;
    for (auto it = hexString.rbegin(); it != hexString.rend(); ++it, ++index) {
        if (HEX_TBL.find(*it) == HEX_TBL.end()) {
            if (*it == '-') {
                result = -result;
                break;
            } else {
                // handle an error
                break;
            }
        }
        result += HEX_TBL[*it] * std::pow(16, index);
    }
    return result;
}


// [8kyu] Grasshopper - Summation
//
// Write a program that finds the summation of every number between 1 and num. The number
// will always be a positive integer greater than 0.
//
// For example:
// summation(8) -> 36
// 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8
int summation(int num) {
    return num * (num + 1) / 2;
}


// [8kyu] Price of Mangoes
//
// There's a 3 for 2 offer on mangoes. For a given price and quantity, calculate
// the total cost of the mangoes.
int mango(int quantity, int price) {
    return (quantity * 2 / 3) * price/*(quantity - quantity / 3) * price*/;
}


// [8kyu] Miles per gallon to kilometers per liter
//
// Sometimes, I want to quickly be able to convert miles per imperial gallon into
// kilometers per liter.
//
// Create an application that will display the number of kilometers per liter(output)
// based on the number of miles per imperial gallon(input).
//
// Make sure to round off the result to two decimal points.If the answer ends with a 0,
// it should be rounded off without the 0. So instead of 5.50, we should get 5.5.
//
// Some useful associations relevant to this kata: 1 Imperial Gallon = 4.54609188 litres
// 1 Mile = 1.609344 kilometres
double converter(int mpg) {
    static const double litresInGallon = 4.54609188;
    static const double kilometresInMile = 1.609344;

    const double kilometres = mpg * kilometresInMile;
    const double kpl = round(100 * (kilometres / litresInGallon)) / 100;

    return kpl;
}


// [8kyu] Wilson primes
//
// Wilson primes satisfy the following condition.Let P represent a prime number.
//
// Then((P - 1)! + 1) / (P * P) should give a whole number.
//
// Your task is to create a function that returns true if the given number is a Wilson prime.
unsigned factorial(unsigned n) {
    return n ? n * factorial(n - 1) : 1;
}

bool amIWilson(unsigned n) {
    if (n == 0 || n == 1)
        return false;
    return (factorial(n - 1) + 1) % (n * n) == 0;
}


// [8kyu] Third Angle of a Triangle
//
// You are given two angles (in degrees) of a triangle.
//
// Write a function to return the 3rd.
//
// Note: only positive integers will be tested.
int otherAngle(int a, int b) {
    static const int angleSum = 180;

    return angleSum - a - b;
}


// [8kyu] The falling speed of petals
// When it's spring Japanese cherries blossom, it's called "sakura" and it's admired a lot.
// The petals start to fall in late April.
//
// Suppose that the falling speed of a petal is 5 centimeters per second (5 cm/s), and it
// takes 80 seconds for the petal to reach the ground from a certain branch.
//
// Write a function that receives the speed (in cm/s) of a petal as input, and returns the
// time it takes for that petal to reach the ground from the same branch.
//
// Notes:
//
//  *  The movement of the petal is quite compilcated, so in this case we can see the velocity
//     as a constant during its falling.
//  *  Pay attention to the data types.
//  *  If the initial velocity is non-positive, the return value should be 0
double sakuraFall(double v) {
    return (v <= 0.0) ? 0.0 : 400.0 / v;
}


// [8kyu] Century from year
// Given a year, return the century it is in.
//
// The first century spans from the year 1 up to and including the year 100,
// the second - from the year 101 up to and including the year 200, etc.
//
// Let's see some examples:
//
//    centuryFromYear(1705) // returns 18
//    centuryFromYear(1900) // returns 19
//    centuryFromYear(1601) // returns 17
//    centuryFromYear(2000) // returns 20
int centuryFromYear(int year) {
    return ((year % 100) == 0) ? year / 100 : year / 100 + 1;
}


// [8kyu] Array plus array
int arrayPlusArray(const std::vector<int>& a, const std::vector<int>& b) {
    return std::accumulate(a.cbegin(), a.cend(), 0) + std::accumulate(b.cbegin(), b.cend(), 0);
}


// [8kyu] Reversed sequence
// Get the number n to return the reversed sequence from n to 1.
// Example : n=5 >> [5,4,3,2,1]
std::vector<int> reverseSeq(int n) {
    std::vector<int> v;
    for (; n != 0; --n)
        v.push_back(n);
    return v;
}


// [8kyu] Can we divide it?
// Your task is to create functionisDivideBy (or is_divide_by) to check if an integer number
// is divisible by each out of two arguments.
//
// A few cases:
//
//    (-12, 2, -6)  ->  true
//    (-12, 2, -5)  ->  false
//
//    (45, 1, 6)    ->  false
//    (45, 5, 15)   ->  true
//
//    (4, 1, 4)     ->  true
//    (15, -5, 3)   ->  true
bool isDivideBy(int number, int a, int b) {
    return number % a == 0 && number % b == 0;
}
