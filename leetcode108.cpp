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
    TreeNode* BST(vector<int>& nums, int left, int right){
        if(left>right) return NULL;
        int mid=(right-left)/2+left;
        TreeNode* res=new TreeNode(nums[mid]);
        res->left=BST(nums,left,mid-1);
        res->right=BST(nums,mid+1,right);
        return res;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return BST(nums,0,n-1);
    }
};