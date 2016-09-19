// Source : https://leetcode.com/problems/intersection-of-two-arrays/
// Author : RQY
// Date   : 2016-09-18
/**********************************************************************************
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.
 **********************************************************************************/
 class Solution {
 public:
     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
         sort(nums1.begin(), nums1.end());
         sort(nums2.begin(), nums2.end());
         int i,j;
         i = j = 0;
         vector<int> ans;
         while(i < nums1.size() && j < nums2.size()){
             if(nums1[i] < nums2[j]){
                 ++i;
             }
             else if(nums1[i] > nums2[j]){
                 ++j;
             }
             else{
                 if(ans.empty())
                     ans.push_back(nums1[i]);
                 else if(ans.back() != nums1[i]){
                     ans.push_back(nums1[i]);
                 }
                 ++i, ++j;
             }
         }
         return ans;
     }
 };
