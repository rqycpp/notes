// Source : https://leetcode.com/problems/climbing-stairs/
// Author : RQY
// Date   : 2016-07-10
/**********************************************************************************
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

原理：即斐波那契数列
公式：F(n) = F(n- 2) + F(n - 1)
初始条件：F(0) = 1, F(1) = 1
 **********************************************************************************/
 class Solution {
 public:
     int climbStairs(int n) {
         int a = 1, b = 1;//初始条件
         if(n <= 1){
             return 1;
         }
         for(int i = 2; i <= n; ++i){
             if(i % 2 == 0)
                 a = a + b;
             else
                 b = b + a;
         }
         return a > b ? a : b;
     }
 };
