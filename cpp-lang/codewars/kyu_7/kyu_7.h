#ifndef KYU_7_H
#define KYU_7_H

#include "kyu_7_global.h"

#include <string>
#include <vector>


// [7kyu] Indexed capitalization
//
// Given a string and an array of integers representing indices, capitalize all letters
// at the given indices.
//
// For example:
//
//    capitalize("abcdef",[1,2,5]) = "aBCdeF"
//    capitalize("abcdef",[1,2,5,100]) = "aBCdeF". There is no index 100.
//
// The input will be a lowercase string with no spaces and an array of digits.
std::string capitalize(std::string s, const std::vector<int> &idxs);


// [7kyu] Get the Middle Character
// You are going to be given a word. Your job is to return the middle character
// of the word. If the word's length is odd, return the middle character. If the
// word's length is even, return the middle 2 characters.
//
// #Examples:
//
//   * Kata.getMiddle("test") should return "es"
//   * Kata.getMiddle("testing") should return "t"
//   * Kata.getMiddle("middle") should return "dd"
//   * Kata.getMiddle("A") should return "A"
//
// #Input
//
// A word (string) of length 0 < str < 1000. You do not need to test for this.
// This is only here to tell you that you do not need to worry about your solution timing out.
//
// #Output
//
// The middle character(s) of the word represented as a string.
std::string getMiddle(const std::string &str);


// [7kyu] Arithmetic progression
// In your class, you have started lessons about arithmetic progression.
// Since you are also a programmer, you have decided to write a function
// that will return the first 'n' elements of the sequence with the given
// common difference 'r' and first element 'a'. Result should be separated by comma and space.
//
// Example:
//
// arithmetic_sequence_elements(1, 2, 5) == '1, 3, 5, 7, 9'
std::string arithmeticSequenceElements(int a, int r, int n);


// [7kyu] Mumbling
//
// Examples:
//
// Accumul::accum("abcd");    // "A-Bb-Ccc-Dddd"
// Accumul::accum("RqaEzty"); // "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy"
// Accumul::accum("cwAt");    // "C-Ww-Aaa-Tttt"
//
// The parameter of accum is a string which includes only letters from a..z and A..Z.
std::string accum(const std::string &s);


// [7kyu] Composing squared strings
//
// A squared string is a string of n lines, each substring being n characters long.
// We are given two n-squared strings. For example:
//
// s1 = "abcd\nefgh\nijkl\nmnop" s2 = "qrst\nuvwx\nyz12\n3456"
//
// Let us build a new string strng of size (n + 1) x n in the following way:
//
//  *  The first line of strng has the first char of the first line of s1 plus the chars
//     of the last line of s2.
//  *  The second line of strng has the first two chars of the second line of s1 plus the
//     chars of the penultimate line of s2 except the last char
//  *  and so on until the nth line of strng has the n chars of the nth line of s1 plus
//     the first char of the first line of s2.
//
// Calling this function compose(s1, s2) we have:
//
// compose(s1, s2) -> "a3456\nefyz1\nijkuv\nmnopq"
// or printed:
// abcd    qrst  -->  a3456
// efgh    uvwx       efyz1
// ijkl    yz12       ijkuv
// mnop    3456       mnopq
std::string compose(const std::string &s1, const std::string &s2);


// [7kyu] Scaling Squared Strings
//
// You are given a string of n lines, each substring being n characters long. For example:
//
// s = "abcd\nefgh\nijkl\nmnop"
//
// We will study the "horizontal" and the "vertical" scaling of this square of strings.
//
// A k-horizontal scaling of a string consists of replicating k times each character of the string (except '\n').
//
//    * Example: 2-horizontal scaling of s: => "aabbccdd\neeffgghh\niijjkkll\nmmnnoopp"
//
// A v-vertical scaling of a string consists of replicating v times each part of the squared string.
//
//    * Example: 2-vertical scaling of s: => "abcd\nabcd\nefgh\nefgh\nijkl\nijkl\nmnop\nmnop"
//
// Function scale(strng, k, v) will perform a k-horizontal scaling and a v-vertical scaling.
//
// #Task:
//
//    * Write function scale(strng, k, v) k and v will be positive integers. If strng == "" return "".
std::string scale(const std::string &s, int k, int v);

#endif // KYU_7_H
