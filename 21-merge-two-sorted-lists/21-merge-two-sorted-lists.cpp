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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*dummy=new ListNode(-1),*p=list1,*q=list2,*prev=dummy;
        while(p&&q){
            if(p->val<q->val){
                prev->next=p;
                p=p->next;
            }
            else{
                prev->next=q;
                q=q->next;
            }
            prev=prev->next;
        }
        while(p){
            prev->next=p;
            p=p->next;
            prev=prev->next;
        }
        while(q){
            prev->next=q;
            q=q->next;
            prev=prev->next;
        }
        return dummy->next;
    }
};