// Source : https://leetcode.com/problems/plus-one/
// Author : RQY
// Date   : 2016-08-25
/**********************************************************************************
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
 **********************************************************************************/
 // 题意：求一个数加1，这个数逐位存放在数组中，最高位在digits[0]。
 class Solution {
 public:
     vector<int> plusOne(vector<int>& digits) {
         int c = 0;
         *digits.rbegin() += 1;
         for(auto it = digits.rbegin(); it != digits.rend(); ++it){
             *it += c;
             c = *it / 10;
             *it %= 10;
         }
         if(c)//考虑最后的进位情况
             digits.insert(digits.cbegin(),1);
         return digits;
     }
 };
