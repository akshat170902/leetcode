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
    void reverse(ListNode*l,ListNode*r){
        
        if(l==r)return;
        ListNode*temp=l->next;
        while(l!=r){
            ListNode*p=temp->next;
            temp->next=l;
            l=temp;
            temp=p;
        }
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
         int lf=left;
        ListNode*first=head,*f=head,*last=head,*l=head;
        while(--left){
            f=first;
            first=first->next;
        }
        while(--right){
            l=last;
            last=last->next;
        }
        
        l=last->next;
        reverse(first,last);
        if(lf==1){
            head=last;
        }
        f->next=last;
        first->next=l;
        return head;
    }
    
};