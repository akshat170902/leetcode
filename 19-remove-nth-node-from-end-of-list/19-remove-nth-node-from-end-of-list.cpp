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
        ListNode*dummy=new ListNode(-1);
        dummy->next=head;
        ListNode*prev=dummy,*forw=dummy;
        
        while(n--){
            forw=forw->next;
        }
        while(forw->next){
            forw=forw->next;
            prev=prev->next;
        }
        
        prev->next=prev->next->next;
        return dummy->next;
    }
};