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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode*dummy=new ListNode(-1),*p=head,*dh=dummy;
        dummy->next=head;
        while(p&&p->next){
        while(p&&p->next&&p->val!=p->next->val){
            dh->next=p;
            dh=p;
            p=p->next;
        }
        if(p&&p->next&&p->val==p->next->val){
        while(p&&p->next&&p->val==p->next->val){
            p=p->next;
        }
            p=p->next;
        }   
        }
        dh->next=p;
        return dummy ->next;
    }
};