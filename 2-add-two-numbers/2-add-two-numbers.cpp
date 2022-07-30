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
        ListNode*p=l1,*q=l2,*dummy=new ListNode(-1),*prev=dummy;
        int carry=0;
        while(p&&q){
            p->val+=q->val+carry;
            carry=p->val/10;
            p->val%=10;
            prev=p;
            p=p->next;
            q=q->next;
        }
        while(p){
            p->val+=carry;
            carry=p->val/10;
            p->val%=10;
            prev=p;
            p=p->next;
        }
        prev->next=q;
        while(q){
            q->val+=carry;
            carry=q->val/10;
            q->val%=10;
            prev=q;
            q=q->next;
        }
        if(carry)
        prev->next=new ListNode(carry);
        return l1;
    }
};