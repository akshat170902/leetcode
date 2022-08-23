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
    bool isPalindrome(ListNode* head) {
        ListNode*slow=head,*fast=head;
        ListNode*prev=nullptr,*forw=head->next;
        
        while(fast&&fast->next){
            fast=fast->next->next;
            
            slow->next=prev;
            prev=slow;
            slow=forw;
            forw=slow->next;
        }
        
        if(fast){
            
            while(prev&&forw){
                if(prev->val!=forw->val)
                    return false;
                prev=prev->next;
                forw=forw->next;
            }
            return true;
        }
        while(prev&&slow){
            if(prev->val!=slow->val)
                return false;
            prev=prev->next;
            slow=slow->next;
        }
        return true;
    }
};