// Source : https://leetcode.com/problems/same-tree/
// Author : RQY
// Date   : 2016-07-24
/**********************************************************************************
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
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
     bool isSameTree(TreeNode* p, TreeNode* q) {
         if(p == NULL && q == NULL)
             return true;
         if(p && q && p->val == q->val){//p，q不为空且节点值相同
             return true && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
             //根比较结果为真 && 左子树结果 && 右子树结果
         }
         else//p，q不能保证同时不为空，或者不能保证节点值相同
             return false;
     }
 };
