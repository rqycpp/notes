// Source : https://leetcode.com/problems/find-peak-element/
// Author : RQY
// Date   : 2016-08-26
/**********************************************************************************
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
 **********************************************************************************/
 class Solution {
 public:
     int findPeakElement(vector<int>& nums) {
         for(int i = 0; i < nums.size(); ++i){//非常本的方法，直接从头开始找，符合条件就返回
             if(nums[i] > nums[i + 1])//nums[-1]负无穷，所以从第1个开始时不需要和左边的元素比较
                 return i;
            //  else{//nums[i] < nums[i + 1];
            //    continue;//此时序列保持单调递增的趋势
            //  }
         }
         return nums.size() - 1;
     }
 };


class Solution {
public:
    int findPeakElement(vector<int>& nums) {//更高效的二分
        int left = 0, right = nums.size() - 1, mid;
        while(left < right){//当left == right时结束循环
            mid = (left + right) / 2;
            if(nums[mid] < nums[mid + 1]){
                left = mid + 1;//peek in [mid + 1, right]
            }
            else{//nums[mid] > nums[mid + 1]
                right = mid;//peek in [left, mid]
            }
        }
        return left;//最后区间长度缩小到1
    }
};
