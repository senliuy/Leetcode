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
    void allWay(TreeNode* root, int &res, int temp){
        if(root->left==NULL && root->right==NULL){
            res+=temp;
            return;
        }
        else{
            if(root->left!=NULL) allWay(root->left, res, 10*temp+root->left->val);
            if(root->right!=NULL) allWay(root->right, res, 10*temp+root->right->val);
        }
    }
public:
    int sumNumbers(TreeNode* root) {
        int res=0;
        if(root==NULL) return res;
        allWay(root,res,root->val);
        return res;
        
    }
};