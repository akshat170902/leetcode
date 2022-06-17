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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*p=head,*Dummy=new ListNode(-1),*ptr=Dummy;
        Dummy->next=head;
        
        while(n--){
            p=p->next;
        }
        
        while(p){
            p=p->next;
            head=head->next;
            ptr=ptr->next;
            
        }
        ptr->next=head->next;
        return Dummy->next;
            
    }
};