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
    ListNode* swapPairs(ListNode* head) {
        ListNode*dummy=new ListNode(-1),*p=head,*dp=dummy;
        dummy->next=head;
        while(p&&p->next){
            ListNode*temp=p->next;
            dp->next=temp;
            p->next=temp->next;
            temp->next=p;
            dp=p;
            p=p->next;
        }
        return dummy->next;
    }
};