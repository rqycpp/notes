// Source : https://leetcode.com/problems/ugly-number-ii/
// Author : RQY
// Date   : 2016-08-22
/**********************************************************************************
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.

Hint:

The naive approach is to call isUgly for every number until you reach the nth one. Most numbers are not ugly. Try to focus your effort on generating only the ugly ones.
An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.
The key is how to maintain the order of the ugly numbers. Try a similar approach of merging from three sorted lists: L1, L2, and L3.
Assume you have Uk, the kth ugly number. Then Uk+1 must be Min(L1 * 2, L2 * 3, L3 * 5).
 **********************************************************************************/
 class Solution {
 public:
     int nthUglyNumber(int n) {//自己生成丑数数列，由小到大排列
         int *data = new int[n];
         data[0] = 1;
         int next = 1;//生成丑数存放索引
         int *p1,*p2,*p3;//3个指针分别记录起乘2、乘3、乘5后大于当前最大丑数的位置
         p1 = p2 = p3 = data;
         while(next < n){
             int min_ugly = min(*p1 * 2, *p2 * 3, *p3 *5);//从生成的三个丑数中选一个最小的
             data[next] = min_ugly;
             //更新各指针
             while(*p1 * 2 <= min_ugly)
                 ++p1;
             while(*p2 * 3 <= min_ugly)
                 ++p2;
             while(*p3 * 5 <= min_ugly)
                 ++p3;
             ++next;

         }
         int ans = data[n -1];
         delete []data;
         return ans;
     }
     int min(int a,int b, int c){
         int temp = std::min(a,b);
         return std::min(temp,c);
     }
 };
