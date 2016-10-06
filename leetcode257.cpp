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
    void allWay(TreeNode* root, vector<string> &res, string temp){
        if(root->left==NULL && root->right==NULL){
            res.push_back(temp);
            return;
        }
        //temp=temp+"->"+to_string(root->val);
        //temp=temp+"->"+s;
        if(root->left!=NULL) allWay(root->left, res, temp+"->"+to_string(root->left->val));
        if(root->right!=NULL) allWay(root->right, res, temp+"->"+to_string(root->right->val));
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root==NULL) return res;
        string temp=to_string(root->val);
        allWay(root,res,temp);
        return res;
    }
};