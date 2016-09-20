// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Author : RQY
// Date   : 2016-09-17
/**********************************************************************************
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
 **********************************************************************************/
 class Solution {
 public:
     int removeDuplicates(vector<int>& nums) {
         if(nums.empty())
             return 0;
         auto res = nums.begin();
         auto first = nums.begin();
         while(++first != nums.end()){
             if(*res != *first)
                 *(++res) = *first;
         }
         return res - nums.begin() + 1;
     }
 };
