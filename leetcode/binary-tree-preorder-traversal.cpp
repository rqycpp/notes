// Source : https://leetcode.com/problems/binary-tree-preorder-traversal/
// Author : RQY
// Date   : 2016-08-11
/**********************************************************************************
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
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
class Solution {//递归
public:
    vector<int> vec;
    vector<int> preorderTraversal(TreeNode* root) {
        preoder(root);
        return vec;
    }
    void preoder(TreeNode* p){
        if(p == NULL)
            return ;
        vec.push_back(p->val);
        if(p->left)
            preoder(p->left);
        if(p->right)
            preoder(p->right);
    }
};

class Solution {//非递归
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>vec;
        stack<TreeNode*>sta;//利用栈
        if(root != NULL)
            sta.push(root);
        while(!sta.empty()){
            TreeNode *temp = sta.top();
            vec.push_back(temp->val);//先根
            sta.pop();
            //为了访问顺序先左后右，所以左右孩子入栈顺序反过来
            if(temp->right)
                sta.push(temp->right);
            if(temp->left)
                sta.push(temp->left);
        }
        return vec;
    }
};
