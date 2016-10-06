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
    vector<TreeNode*> genTrees(int start, int end){
        vector<TreeNode*> ret;
        if(start>end){
            ret.push_back(NULL);
            return ret;
        }
        
        for(int i=start; i<=end; i++){
            vector<TreeNode*> leftTree=genTrees(start,i-1);
            vector<TreeNode*> rightTree=genTrees(i+1,end);
            for(int j=0; j<leftTree.size(); j++){
                for(int k=0; k<rightTree.size(); k++){
                    TreeNode *node = new TreeNode(i + 1);
                    //ret.push_back(node);
                    node->left = leftTree[j];
                    node->right = rightTree[k];
                    ret.push_back(node);
                }
            }
        }
        
        return ret;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if(n==0) return res;
        return genTrees(0, n-1);
    }
};