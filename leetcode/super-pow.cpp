// Source : https://leetcode.com/problems/super-pow/
// Author : RQY
// Date   : 2016-09-16
/**********************************************************************************
Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.

Example1:

a = 2
b = [3]

Result: 8
Example2:

a = 2
b = [1,0]

Result: 1024
 **********************************************************************************/
 //解题思路
 //http://blog.csdn.net/rqy1994/article/details/52357084
 class Solution {
 public:
     const int base = 1337;
     int powmod(int a, int k){
         a %= base;
         int ans = 1;
         while(k--){
             ans *= a;
             ans %= base;
         }
         return ans;
     }
     int superPow(int a, vector<int>& b) {
         if(b.empty())
             return 1;
         int last_digit = b.back();
         b.pop_back();
         return powmod( superPow(a, b), 10) * powmod(a, last_digit) % base;
     }
 };
