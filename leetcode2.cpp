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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* dummyHead=l1;
        while ( l1 && l2){
            int sum=carry+l1->val+l2->val;
            l1->val=sum%10;
            carry=sum/10;
            l1=l1->next;
            l2=l2->next;
        }
        if( l1 && !l2 ){
            while( l1 ){
                if(carry==0) break;
                int sum = carry + l1->val;
                l1->val = sum%10;
                carry=sum/10;
                l1=l1->next;
            }
        }
        else{
            ListNode* p=dummyHead;
            while( p->next ) p=p->next;
            p->next=l2;
            while( l2 ){
                if( carry == 0 ) break;
                int sum=carry+l2->val;
                l2->val=sum%10;
                carry=sum/10;
                l2=l2->next;
            }
        }
        if( carry==1 ){
            ListNode *p=dummyHead;
            while(p->next) p=p->next;
            ListNode *node=new ListNode(1);
            p->next=node;
        }
        return dummyHead;
    }
};