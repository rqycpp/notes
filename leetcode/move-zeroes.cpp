// Source : https://leetcode.com/problems/move-zeroes/
// Author : RQY
// Date   : 2016-08-25
/**********************************************************************************
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
 **********************************************************************************/
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		for (int i = 0; i < nums.size() - 1; ++i) {
			if (nums[i] != 0) continue;//前一个数不是0就继续循环
			for (int j = i + 1; j < nums.size(); ++j) {
				if (nums[j] != 0) {//前一个数为0，后一个数非零
					swap(nums[i], nums[j]);//交换
					break;//跳出循环，在搜索下一个数
				}
			}
		}
	}
};

//学习了一下别人的代码，这个时间复杂度低
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int index = 0, current = 0; current < nums.size(); ++current){
            if(nums[current] != 0)
                swap(nums[index++], nums[current]);
            //若nums[current] == 0, index滞后，current寻找不为0的数和它进行交换
        }
    }
};
