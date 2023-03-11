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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* func(ListNode*head,int n){
        // if(head){
        //     cout<<head->val<<endl;
        // }
        if(n<=0){
            return nullptr;
        }
        if(n==1){
            return new TreeNode(head->val);
        }
        int mid=n/2;
        ListNode*temp=head;
        while(mid--){
            temp=temp->next;
        }
        TreeNode*ans=new TreeNode(temp->val,func(head,n/2),func(temp->next,n-n/2-1));
        return ans;
        
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head){
            return nullptr;
        }
        int n=0;
        ListNode*temp=head;
        while(temp){
            n++;
            temp=temp->next;
        }
        return func(head,n);
    }
};