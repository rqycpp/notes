// Source : https://leetcode.com/problems/maximum-subarray/
// Author : RQY
// Date   : 2016-08-25
/**********************************************************************************
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 **********************************************************************************/
 class Solution {
 public:
     int maxSubArray(vector<int>& nums) {
         if(nums.empty())
             return 0;
         int curSum = 0;
         int maxSum = 0x80000000;//非常小的负数
         for(int i = 0; i < nums.size(); ++i){
             if(curSum <= 0){//重新选择起点，抛弃之前的数据和
                 curSum = nums[i];
             }
             else{
                 curSum += nums[i];//累加
             }
             maxSum = max(maxSum, curSum);//更新maxSum
         }
         return maxSum;
     }
 };
