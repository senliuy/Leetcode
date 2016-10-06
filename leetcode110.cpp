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
    int treeHeight(TreeNode* root){
        if(root==NULL) return 0;
        else return max(treeHeight(root->left), treeHeight(root->right))+1;
    }
    bool helper(TreeNode* root){
        if(root==NULL) return true;
        if(abs(treeHeight(root->left)-treeHeight(root->right))>=2) return false;
        else return helper(root->left) && helper(root->right);
    }
public:
    bool isBalanced(TreeNode* root) {
        return helper(root);
    }
};