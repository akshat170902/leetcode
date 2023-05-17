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
    int pairSum(ListNode* head) {
        ListNode*dummy=new ListNode(-1);
        dummy->next=head;
        ListNode*hare=dummy,*tor=dummy,*prev=dummy;
        ListNode*forw;
        while(hare->next){
            hare=hare->next->next;
            // cout<<tor->val<<endl;
            forw=tor->next;
            
            tor->next=prev;
            prev=tor;
            tor=forw;
            
            
        }
        ListNode*cur1=tor,*cur2=tor->next;
        tor->next=prev;
        int ans=0;
        while(cur2){
            cout<<cur1->val<<" "<<cur2->val<<endl;
            ans=max(ans,cur1->val+cur2->val);
            cur1=cur1->next;
            cur2=cur2->next;
        }
        return ans;
    }
};