/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *A, ListNode *B) {
        ListNode*p=A,*q=B;
        ListNode*pt=A,*qt=B;
        int a=0,b=0;
        while(pt){
            a++;
            pt=pt->next;
        }
        while(qt){
            b++;
            qt=qt->next;
        }
        for(int i=0;i<abs(a-b);i++){
            a<b?q=q->next:p=p->next;
        }
        while(p!=q){
            p=p->next;
            q=q->next;
        }
        return p;
    }
};