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
    bool isValidBST(TreeNode* root,long l=(long)INT_MIN-1,long h=(long)INT_MAX+1) {
        if(!root)
            return true;
        if(root->val>=h||root->val<=l)
            return false;
        return isValidBST(root->left,l,root->val)&&isValidBST(root->right,root->val,h);
    }
};