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
    vector<int> ans;
    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return ans;
    }
    void postorder(TreeNode *p){
        if(p == NULL)
            return;
        if(p->left)
            postorder(p->left);
        if(p->right)
            postorder(p->right);
        ans.push_back(p->val);
    }

};
