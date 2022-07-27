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
    TreeNode*helper(TreeNode*&root){
        if(root==nullptr)return nullptr;
        if(root->right==nullptr&&root->left==nullptr)return root;
        TreeNode*l=helper(root->left);
        TreeNode*r=helper(root->right);
        if(root->left){
        TreeNode*temp=root->right;
        
        root->right=root->left;
        root->left=nullptr;
        
        l->right=temp;}
        if(!r)return l;
        return r;
    }
    void flatten(TreeNode* root) {
        helper(root);
    }
};