// Source : https://leetcode.com/problems/jump-game/
// Author : RQY
// Date   : 2016-08-30
/**********************************************************************************
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
 **********************************************************************************/
class Solution {
public:
    bool canJump(vector<int>& nums) {//贪心
        int reach = 0;//所得到达最远位置的索引
        for(int i = 0; i < nums.size() && i <= reach; ++i){//从头开始扫描，i表示目前访问的位置，
                        //当开始访问i位置时，若i > reach，表示目前的位置是无法达到的，要终止循环
                        //eg:[3,2,1,0,4] ,当访问到0时，reach = 3，继续访问4，此时i == 4 < reach，访问失败

            reach = max(reach, i + nums[i]);//过程中更新目前所能到达的最远位置
            if(reach >= nums.size() - 1)//如果目前所能到达的最远位置 >= last index 返回true
                return true;
        }
        return false;
    }
};
