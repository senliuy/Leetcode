/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL) return head;
        ListNode* res=new ListNode(INT_MIN);
        while(head){
            ListNode *cur=head;
            head=head->next;
            ListNode* res_cur=res;
            while(res_cur->next!=NULL && cur->val > res_cur->next->val){
                res_cur=res_cur->next;
            }
            cur->next=res_cur->next;
            res_cur->next=cur;
        }
        head=res->next;
        return head;
    }
};