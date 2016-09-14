// Source : https://leetcode.com/problems/problems/path-sum/
// Author : RQY
// Date   : 2016-09-14
/**********************************************************************************
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 **********************************************************************************/
 /**
  * Definition for a binary tree node.
  * struct TreeNode {
  *     int val;
  *     TreeNode *left;
  *     TreeNode *right;
  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  * };
  */
 class Solution {
 public:
     bool ans = false;
     bool hasPathSum(TreeNode* root, int sum) {
         traversal(root, 0, sum);
         return ans;
     }
     void traversal(TreeNode *p, int sum, int des){
         if(!p){
             return;
         }

         sum += p->val;
         if(!p->left && !p->right && sum == des){
             ans = true;
         }
         if(!ans){
             traversal(p->left, sum, des);
             traversal(p->right, sum, des);
         }
     }

     //方法2,更加简洁
     bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
            return false;
        if(!root->left && !root->right && root->val == sum)
            return true;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
 };
