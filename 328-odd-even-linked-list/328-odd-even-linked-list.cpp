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
    ListNode* oddEvenList(ListNode* head) {
        if(!head||!head->next)
            return head;
        ListNode*dummy1=new ListNode(-1);
        ListNode*o=dummy1;
        
        ListNode*dummy2=new ListNode(-1);
        ListNode*e=dummy2;
        bool odd=true;
        while(head){
            if(odd){
                o->next=head;
                o=head;
                odd=false;
            }
            else{
                e->next=head;
                e=head;
                odd=true;
            }
            head=head->next;
        }
        o->next=dummy2->next;
        e->next=nullptr;
        return dummy1->next;
    }
};