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
     
    ListNode* reverseList(ListNode* head) {
        if(!head||head->next==nullptr){
            return head;
            
        } 
        
        ListNode*prec=head;
        
        head=head->next;
        prec->next=nullptr;
        while(head){
            ListNode *temp=head->next;
             
            head->next=prec;
            prec=head;
            head=temp;
            
        }
        return prec;
    }
};