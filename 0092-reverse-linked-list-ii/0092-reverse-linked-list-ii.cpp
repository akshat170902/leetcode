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
    ListNode* reverseBetween(ListNode* head, int L, int R) {
        ListNode*dummy=new ListNode(),*prev=dummy,*left=head,*right=head,*forw=head->next;
        dummy->next=head;
        int dif=(R-L);
        while(--L){
            prev=left;
            left=forw;
            right=forw;
            forw=forw->next;
        }
        
        while(dif--){
            ListNode*temp=forw->next;
            forw->next=right;
            right=forw;
            forw=temp;
        }
        prev->next=right;
        left->next=forw;
        return dummy->next;
    }
};