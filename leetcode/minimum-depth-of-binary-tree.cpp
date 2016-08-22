// Source : https://leetcode.com/problems/minimum-depth-of-binary-tree/
// Author : RQY
// Date   : 2016-08-12
/**********************************************************************************
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
     int minDepth(TreeNode* root) {
         int depth = 0;
         return minDepth(root, depth);
     }
     int minDepth(TreeNode* p, int depth){//比最大深度复杂一点点
         if(p == NULL)
             return depth;
         ++depth;//如果该节点可以访问，深度加一
         if(p->left == NULL && p->right == NULL)
             return depth;//如果左右孩子为空，直接把最新深度返回

         int ldepth = 0xfffffff;//初始化成一个大数
         int rdepth = 0xfffffff;
         if(p->left)
             ldepth = minDepth(p->left, depth);
         if(p->right)
             rdepth = minDepth(p->right, depth);
         return min(ldepth, rdepth);
     }
 };
