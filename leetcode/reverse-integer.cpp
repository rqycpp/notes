// Source : https://leetcode.com/problems/reverse-integer/
// Author : RQY
// Date   : 2016-08-28
/**********************************************************************************
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

 //如果将数字存为字符，进行反转要注意这个问题
If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

//要注意溢出问题
Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

//如果最终结果溢出，返回0
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

Update (2014-11-10):
Test cases had been added to test the overflow behavior.
 **********************************************************************************/
 //关于INT_MAX 和 INT_MIN，见http://www.cplusplus.com/reference/climits/
 class Solution {
 public:
     int reverse(int x) {
         int res = 0;
         while(x){
             if(res > INT_MAX / 10 || res < INT_MIN / 10)//在过程中判断中间结果是否已经大于INT_MAX和小于INT_MIN
                 return 0;                               //若此时已经大于或小于 最值/10，则下一步 * 10 + x % 10 一定会溢出
             res = res * 10 + x % 10;
             x /= 10;
         }
         return res;
     }
 };
//还可以将res声明为longlong类型，最后用res和最值进行比较。
