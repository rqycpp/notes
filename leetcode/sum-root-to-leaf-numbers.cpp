// Source : https://leetcode.com/problems/sum-root-to-leaf-numbers/
// Author : RQY
// Date   : 2016-09-14
/**********************************************************************************
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
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
     vector<int>ans;//保存结果
     int sumNumbers(TreeNode* root) {
         traversal(root, 0);
         int sum = 0;
         for(auto i : ans)
             sum += i;
         return sum;
     }
     void traversal(TreeNode *p, int number){//遍历二叉树
         if(!p){
             return;
         }
         number = number * 10 + p->val;
         if(!p->left && !p->right){//叶子节点
             ans.push_back(number);//存结果
         }
         traversal(p->left, number);
         traversal(p->right, number);

     }
     
 };
