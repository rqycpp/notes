// Source : https://leetcode.com/problems/power-of-three/
// Author : RQY
// Date   : 2016-07-07
/**********************************************************************************
Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

Hint:http://blog.csdn.net/ebowtang/article/details/50485622

1. 3^x = n -> log3(n) = x, 已知n，当求得x是正整数时，n是3的整数次幂
2. 或者用int范围内的最大的3的整数次幂作为被除数，除以n，若乘除则n是3的整数次幂
3. 直接打表
 **********************************************************************************/
 class Solution { //采用方法1
 public:
     bool isPowerOfThree(int n) {
         double logRes = log10(n) / log10(3); //换底公式，log10(n) / log10(3) = log3(n)
         if(logRes - int(logRes) == 0){
             return true;
         }
         else{
             return false;
         }
     }
 };
