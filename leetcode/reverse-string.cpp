// Source : https://leetcode.com/problems/reverse-string/
// Author : RQY
// Date   : 2016-07-07
/**********************************************************************************
Write a function that takes a string as input and returns the string reversed.
 **********************************************************************************/
 class Solution {
 public:
     string reverseString(string s) {
         string rs(s.rbegin(), s.rend());
         return rs;
     }
 };
