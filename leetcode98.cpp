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
    bool isValid(TreeNode* root, long maxV, long minV){
        if(root==NULL) return true;
        if(maxV <= root->val || minV >= root->val) return false;
        return isValid(root->left, root->val, minV) && isValid(root->right, maxV, root->val);
    }
    bool isValidBST(TreeNode* root) {
        return isValid(root,LONG_MAX,LONG_MIN);
        //return true;
    }
};