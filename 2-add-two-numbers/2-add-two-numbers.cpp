/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p=l1,*q=l2,*pptr=l1,*qptr=l2;
        
        int carry=0;
        while(p&&q){
            int temp=(p->val+q->val+carry);
            p->val=temp%10;
            carry=temp/10;
            pptr=p;
            p=p->next;
            qptr=q;
            q=q->next;
            
        }
        if(!p){
            pptr->next=q;
            p=q;
        }
         
            while(carry&&p){
            int temp=(p->val+carry);
            p->val=temp%10;
            carry=temp/10;
                pptr=p;
            p=p->next;}
             if(carry!=0){
                 ListNode*t=new ListNode(carry);
                 pptr->next=t;
             }
        return l1;
    }
};