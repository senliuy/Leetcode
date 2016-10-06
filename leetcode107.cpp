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
        if(level==res.size()) res.push_back({});
        res[level].push_back(root->val);
        if(root->left) helper(root->left,res,level+1);
        if(root->right) helper(root->right,res,level+1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) return res;
        helper(root,res,0);
        int h=res.size();
        vector<vector<int>> ans;
        for(int i=h-1;i>=0;i--){
            ans.push_back(res[i]);
        }
        return ans;
    }
};