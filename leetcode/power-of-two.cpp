// Source : https://leetcode.com/problems/power-of-two/
// Author : RQY
// Date   : 2016-07-08
/**********************************************************************************
Given an integer, write a function to determine if it is a power of two.
1.判断码重是否为1
2.或者直接判断 x&(x - 1) == 0 是否成立。
 **********************************************************************************/
 class Solution {
 public:
     bool isPowerOfTwo(int n) {
         if(n < 0){//题目样例有负数
             return false;
         }
         int count = 0;
         while(n){//这里计算码重，效率比直接判断x&(x - 1)差一些，犯懒了，就不改了。
             n = n & (n - 1);
             ++count;
         }
         if(count == 1){
             return true;
         }
         else{
             return false;
         }
     }
 };
