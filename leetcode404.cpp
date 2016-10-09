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
private:
    void helper(TreeNode* &root, int &res){
        if(root==NULL) return;
        if(root->left!=NULL && root->left->left==NULL and root->left->right==NULL)  res+=root->left->val;
        if(root->left!=NULL)   helper(root->left, res);
        if(root->right!=NULL)  helper(root->right, res);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int res=0;
        helper(root,res);
        return res;
    }
};