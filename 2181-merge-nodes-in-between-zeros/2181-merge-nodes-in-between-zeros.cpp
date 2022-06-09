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
    ListNode* mergeNodes(ListNode* head) {
        ListNode*dummy=new ListNode(-1),*q=dummy;
        while(head){
            int sum=0;
            while(head&&head->val!=0 ){
                sum+=head->val;
                head=head->next;
            }
             
                head=head->next;
            
            if(sum!=0){
             ListNode*p=new ListNode(sum);
            dummy->next=p;
            dummy=p;   
            }
            
        }
        return q->next;
    }
};