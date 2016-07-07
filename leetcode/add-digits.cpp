// Source : https://leetcode.com/problems/add-digits/
// Author : RQY
// Date   : 2016-07-07
/**********************************************************************************
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Hint:https://en.wikipedia.org/wiki/Digital_root
 **********************************************************************************/
 class Solution {
 public:
     int addDigits(int num) {
         return 1 + (num - 1) % 9;
     }
 };
