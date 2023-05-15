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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *m=head;
        int n=0;
        while (m){
            n++;
            m=m->next;
        }
        ListNode*kn=head;
        int l=n-k;
        k=k-1;
        while(k--){
            kn=kn->next;
            
        }
        
        ListNode*ln=head;
                while(l--){
            ln=ln->next;
            
        }
        int temp=kn->val;
        kn->val=ln->val;
        ln->val=temp;
        return head;
        
    }
};