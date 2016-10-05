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
    void helper(TreeNode* root, vector<vector<int>> &res, int level){
        if(root==NULL) return;
        if(res.size() == level) res.push_back({});
        res[level].push_back(root->val);
        if(root->left)    helper(root->left,res,level+1);
        if(root->right)   helper(root->right,res,level+1);
        
        
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) return res;
        int level=0;
        helper(root,res,level);
        return res;
    }
};