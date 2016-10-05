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
    bool isSym(TreeNode* left, TreeNode* right){
        if(left==NULL) return right==NULL;
        if(right==NULL) return left==NULL;
        if(left->val!=right->val) return false;
        if(!isSym(left->right, right->left)) return false;
        if(!isSym(left->left, right->right)) return false;
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        else return isSym(root->left, root->right);
    }
};