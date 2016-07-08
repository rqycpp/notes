// Source : https://leetcode.com/problems/power-of-four/
// Author : RQY
// Date   : 2016-07-08
/**********************************************************************************
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
Given num = 16, return true. Given num = 5, return false.

Follow up: Could you solve it without loops/recursion?

Credits:
Special thanks to @yukuairoy for adding this problem and creating all test cases.

Hint:http://www.cnblogs.com/grandyang/p/5403783.html
 **********************************************************************************/
 class Solution {//采用与power-of-three相同的方法
 public:
     bool isPowerOfFour(int num) {
         double logRes = log10(num) / log10(4);//换底公式
         return (logRes - int(logRes) == 0);
     }
 };
