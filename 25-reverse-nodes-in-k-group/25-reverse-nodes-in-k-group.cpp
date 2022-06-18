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
    ListNode*reverse_ll(ListNode*head,ListNode*tail){
        ListNode*ptr=head->next;
        ListNode*prev=head;
        while(ptr!=tail){
            ListNode*temp=ptr->next;
            ptr->next=prev;
            prev=ptr;
            ptr=temp;
        }
        ListNode*ans=head->next;
        head->next->next=tail;
        head->next=prev;
        return ans;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*tail=head,*dummy=new ListNode(-1),*dp=dummy;
        dummy->next=head;
        while(1){
            for(int i=0;i<k;i++){
                if(tail==nullptr)return dummy->next;
                tail=tail->next;
            }
            dp=reverse_ll(dp,tail);
        }
    }
};