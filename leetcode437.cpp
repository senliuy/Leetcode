//
//  main.cpp
//  Longest Palindrome
//
//  Created by liuyan on 2016/10/9.
//  Copyright © 2016年 liuyan. All rights reserved.
//

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
    int rootPathSum(TreeNode* root, int sum){
        int res=0;
        if(root->val == sum) res+=1;
        if(root->left) res += rootPathSum(root->left, sum - root->val);
        if(root->right) res += rootPathSum(root->right, sum - root->val);
        return res;
    }
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL) return 0;
        int res=rootPathSum(root, sum);
        if(root -> left) res += pathSum(root->left, sum);
        if(root -> right) res += pathSum(root->right, sum);
        return res;
    }
};