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
     //https://discuss.leetcode.com/topic/42914/1-line-c-solution-without-confusing-bit-manipulations
     bool isPowerOfFour(int num) {
       return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
      //     大于0       码重为1                   是3的倍数
    }
    bool isPowerOfFour(int num){
      return num > 0 && (num & (num - 1) == 0) && (num & 0x55555555) == 0;//4^n 二进制的奇数位为1，且只有一个1
    }
 };
