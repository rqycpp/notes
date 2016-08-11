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
    vector<int>ans;
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return ans;
    }
    void inorder(TreeNode *p){
        if(p == NULL)
            return;
        if(p->left){
            inorder(p->left);
        }
        ans.push_back(p->val);
        if(p->right){
            inorder(p->right);
        }
    }
};
