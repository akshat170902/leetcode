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
    ListNode*reversell(ListNode*head,int k){
        
        ListNode*prev=nullptr;
        
        while(k--){
            ListNode*temp=head->next;
            head->next=prev;
            prev=head;
            head=temp;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*dummy=new ListNode(-1);
        dummy->next=head;
        ListNode*prev=dummy,*p=head;
       
        while(p){
            ListNode*temp=prev->next;
            bool flag=true;
            for(int i=0;i<k;i++){
                if(!p){
                flag=false;
                break;
                }
                p=p->next;
                
            }
            if(!flag)break;
            prev->next=reversell(prev->next,k);
            temp->next=p;
            prev=temp;
        }
        return dummy->next;
    }
};