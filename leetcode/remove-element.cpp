// Source : https://leetcode.com/problems/remove-element/
// Author : RQY
// Date   : 2016-08-28
/**********************************************************************************
Given an array and a value, remove all instances of that value in place and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:
Given input array nums = [3,2,2,3], val = 3

Your function should return length = 2, with the first two elements of nums being 2.

Hint:

Try two pointers.//快慢指针
Did you use the property of "the order of elements can be changed"?
What happens when the elements to remove are rare?//采用方法2
 **********************************************************************************/
 class Solution {
 public:
     //方法1
     int removeElement(vector<int>& nums, int val) {
         int i = 0;//分别设置慢指针i，快指针j
         for(int j = 0; j < nums.size(); ++j){
             if(nums[j] != val){//此时nums[j] != val
                 nums[i] = nums[j];//拷贝
                 ++i;//增加
             }
             //当nums[j] == val时跳过这个元素，不管它，增加j
         }
         nums.erase(nums.begin() + i, nums.end());
         return nums.size();
     }

     //方法2
     int removeElement(vector<int>& nums, int val) {
         int n = nums.size();
         for(int i = 0; i < n;){
             if(nums[i] == val){//此时我们将当前元素与尾元素交换
                 nums[i] = nums[n - 1];//把当前元素当成空气无视
                 --n;//长度减1
                 //此处不++i的原因是，交换过来的尾元素很可能等于val，所以在判断一次
             }
             else{
                 ++i;
             }
         }
         nums.erase(nums.begin() + n, nums.end());
         return nums.size();
     }
 };
