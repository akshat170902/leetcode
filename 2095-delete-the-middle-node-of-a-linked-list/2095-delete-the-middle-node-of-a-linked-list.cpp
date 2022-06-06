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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode*n=head,*p=head,*b=head;
        while(p&&p->next){
            if(n!=head)b=b->next;
            n=n->next;
            p=p->next->next;
        }
        if(n==head)return n->next;
        b->next=n->next;
        return head;
        
    }
};