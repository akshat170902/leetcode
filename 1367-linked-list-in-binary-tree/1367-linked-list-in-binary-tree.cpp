class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;
        return dfs(root, head) || isSubPath(head, root->left) ||
               isSubPath(head, root->right);
    }

private:
    bool dfs(TreeNode* node, ListNode* head) {
        if (!head) return true;  // All nodes in the list matched
        if (!node)
            return false;  // Reached end of tree without matching all nodes
        if (node->val != head->val) return false;  // Value mismatch
        // Check both left and right children
        return dfs(node->left, head->next) || dfs(node->right, head->next);
    }
};