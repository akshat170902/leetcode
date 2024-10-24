class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // Both trees are empty
        if (root1 == nullptr && root2 == nullptr) {
            return true;
        }
        // Just one of the trees is empty
        if (root1 == nullptr || root2 == nullptr) {
            return false;
        }
        // Corresponding values differ
        if (root1->val != root2->val) {
            return false;
        }

        // Check if corresponding subtrees are flip equivalent
        bool noSwap = flipEquiv(root1->left, root2->left) &&
                      flipEquiv(root1->right, root2->right);
        // Check if opposite subtrees are flip equivalent
        bool swap = flipEquiv(root1->left, root2->right) &&
                    flipEquiv(root1->right, root2->left);

        return swap || noSwap;
    }
};