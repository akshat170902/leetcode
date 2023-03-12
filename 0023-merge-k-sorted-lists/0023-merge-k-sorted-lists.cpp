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
    ListNode* mergeKLists(vector<ListNode*> lists) {
        ListNode*dummy=new ListNode(-1),*dp=dummy,*ptr=dummy;
        int mini=1e9;
        while(1){
            int mini=1e9;
            int idx=-1;
            for(int i=0;i<lists.size();i++){
                if(lists[i]==nullptr)continue;
                if(mini>lists[i]->val){
                    mini=lists[i]->val;
                    idx=i;
                    ptr=lists[i];
                }
            }
            if(mini<1e9){
            dp->next=ptr;
            dp=ptr;
            lists[idx]=lists[idx]->next;
            }
            else{
                dp->next=nullptr;
                break;
            }
        }
        return dummy->next;
    }
};