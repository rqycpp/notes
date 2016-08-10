// Source : https://leetcode.com/problems/symmetric-tree/
// Author : RQY
// Date   : 2016-07-24
/**********************************************************************************
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
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
     bool isSymmetric(TreeNode* root) {
         if(root == NULL)//树为空
             return true;
         if(root->left == NULL && root->right == NULL)//只有一个根节点
             return true;
         if(root->left && root->right){//左右子树不为空，去掉根，拆成两棵树，判断是否镜像
             return isMirror(root->left,root->right);
         }
         return false;//左右子树不对称
     }
     bool isMirror(TreeNode *p, TreeNode *q){//判断两棵树是否镜像
         if(p == NULL && q == NULL)//两棵树为空
             return true;
         if(p && q && p->val == q->val){//两棵树不为空且节点值相等
             return true && isMirror(p->left, q->right) && isMirror(p->right, q->left);//这里和判断两棵树是否相等十分相似
             //最终结果：当前结点 && 左子树结果 && 右子树结果
         }
         return false;
     }
 };
