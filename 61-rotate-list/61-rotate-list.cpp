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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||!head->next)return head;
        int n=0;
        for(ListNode*temp=head;temp;temp=temp->next){
            n++;
        }
        k=k%n;
        if(k==0){
            return head;
        }
        else{
            int dif=n-k-1;
            ListNode*temp=head;
            while(dif--){
                temp=temp->next;
            }
            ListNode*ans=temp->next,*tra=ans;
            temp->next=nullptr;
            while(tra->next){
                tra=tra->next;
            }
            tra->next=head;
            head=ans;
        }
        return head;
    }
};