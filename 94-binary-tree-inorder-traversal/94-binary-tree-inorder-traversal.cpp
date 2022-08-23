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
    void inorderFinder(TreeNode*root,vector<int>&inorderSequence){
        if(root==nullptr)
            return;
        inorderFinder(root->left,inorderSequence);
        inorderSequence.push_back(root->val);
        inorderFinder(root->right,inorderSequence);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inorderSequence;
        inorderFinder(root,inorderSequence);
        return inorderSequence;
    }
};