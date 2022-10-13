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
    void deleteNode(ListNode* node) {
        
        ListNode*n=node->next;
        node->val=n->val;
        node->next=n->next;
        
        // delete(node);
    }
};