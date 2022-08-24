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
    void rec(TreeNode*root,vector<int>&preorder){
        if(root){
            preorder.push_back(root->val);
            rec(root->left,preorder);
            rec(root->right,preorder);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>preorder;
        rec(root,preorder);
        return preorder;
    }
};