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
    void helper(vector<vector<int>> &res, vector<int> temp, TreeNode* root, int sum){
        if(root==NULL) return;
        temp.push_back(root->val);
        if(!root->left && !root->right && sum==root->val){
            res.push_back(temp);
            return;
        }
        else{
            helper(res, temp, root->left, sum - root->val);
            helper(res, temp, root->right, sum - root->val);
        }
    }
public:
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if(root==NULL) return res;
        vector<int> temp;
        helper(res,temp,root,sum);
        return res;
    }
};