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
    ListNode* rotateRight(ListNode* head, int n) {
        if(head==nullptr)return head;
        ListNode*temp=head,*p=head,*k=head;
        int l=0;
        while(temp){
            l++;
            temp=temp->next;
        }
        n=n%l;
        if(n==0)return head;
        while(n--){
            k=k->next;
            
        }
        while(k->next){
            k=k->next;
            p=p->next;
        }
        k->next=head;
        head=p->next;
        p->next=nullptr;
        return head;
    }
};