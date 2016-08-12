// Source : https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Author : RQY
// Date   : 2016-08-12
/**********************************************************************************
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
     int maxDepth(TreeNode* root) {
         int depth = 0;
         int ans = maxDepth(root,depth);
         return ans;
     }
     int maxDepth(TreeNode *p, int depth){
         if(p == NULL)
             return depth;//节点为空直接返回深度
         ++depth;//节点可访问，深度加一
         int ldepth = maxDepth(p->left,depth);//左子树最大深度
         int rdepth = maxDepth(p->right,depth);//右子树最大深度
         return max(ldepth,rdepth);//返回最大值
     }
 };
