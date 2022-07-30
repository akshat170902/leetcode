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
        ListNode*hare=head,*tor=head,*prev=nullptr;
        while(hare&&hare->next){
            hare=hare->next->next;
            ListNode*temp=tor->next;
            tor->next=prev;
            prev=tor;
            tor=temp;
        }
        
        if(hare){
            tor=tor->next;
        }
        while(tor){
            // cout<<tor->val;
            if(tor->val!=prev->val){
                return false;
            }
            tor=tor->next;
            prev=prev->next;
        }
        return true;
    }
};