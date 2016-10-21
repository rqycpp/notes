// Source : https://leetcode.com/problems/balanced-binary-tree/
// Author : RQY
// Date   : 2016-09-16
/**********************************************************************************
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which
the depth of the two subtrees of every node never differ by more than 1.
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
     bool isBalanced(TreeNode* root) {
         if(!root)
             return true;
         bool left = isBalanced(root->left);//判断左子树是否为平衡二叉树
         bool right = isBalanced(root->right);//判断右子树是否为平衡二叉树
         if(left && right){//判断当前根节点
             int ldepth = maxDepth(root->left);
             int rdepth = maxDepth(root->right);
             return abs(ldepth - rdepth) <= 1;
         }
         return false;
     }
     int maxDepth(TreeNode *p){//最大深度
         if(!p)
             return 0;
         return max(maxDepth(p->left), maxDepth(p->right)) + 1;
     }
 };
