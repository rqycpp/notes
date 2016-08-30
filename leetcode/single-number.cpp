// Source : https://leetcode.com/problems/single-number/
// Author : RQY
// Date   : 2016-08-30
/**********************************************************************************
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 **********************************************************************************/
 //任何一个数异或它自身都得0
 //任何一个数异或0后结果不便
 //从头异或到尾，数组中出现2次的数异或后会得0，最终结果就是那个出现过1次的数。
 //https://discuss.leetcode.com/topic/1916/my-o-n-solution-using-xor/5
 class Solution {
 public:
     int singleNumber(vector<int>& nums) {
         int res = 0;
         for(int i = 0; i < nums.size(); ++i){
             res ^= nums[i];
         }
         return res;
     }
 };
