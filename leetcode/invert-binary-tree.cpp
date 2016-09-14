// Source : https://leetcode.com/problems/invert-binary-tree/
// Author : RQY
// Date   : 2016-09-14
/**********************************************************************************
Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1
Trivia:
This problem was inspired by this original tweet by Max Howell:
Google: 90% of our engineers use the software you wrote (Homebrew),
but you can’t invert a binary tree on a whiteboard so fuck off.
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
     TreeNode* invertTree(TreeNode* root) {
         if(!root)
             return root;
         TreeNode *left = invertTree(root->left);
         TreeNode *right = invertTree(root->right);
         root->left = right;
         root->right = left;
         return root;
     }
 };
