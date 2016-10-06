/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* helper(ListNode* head, ListNode* tail){
        //cout<<"==="<<endl;
        if(head==tail) return NULL;
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=tail && fast->next!=tail){
            fast=fast->next->next;
            slow=slow->next;
        }
        TreeNode* res=new TreeNode(slow->val);
        res->left=helper(head, slow);
        res->right=helper(slow->next, tail);
        return res;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return helper(head,NULL);
    }
};