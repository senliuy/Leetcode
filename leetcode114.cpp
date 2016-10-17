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
    void flatten(TreeNode* root) {
        if( !root || !root->left && !root->right) return;
        if( root->left ) flatten(root->left);
        if( root->right )flatten(root->right);
        TreeNode* r_temp=root->right;
        root->right=root->left;
        root->left=NULL;
        while(root->right) root=root->right;
        root->right=r_temp;
    }
};