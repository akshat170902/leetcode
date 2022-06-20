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
    void helper(TreeNode*root,int &ans,int tar){
        if(root==nullptr)return ;
        if(root->val>=tar){
            ans++;
            tar=root->val;
        }
        helper(root->left,ans,tar);
        helper(root->right,ans,tar);
        
        
    }
    int goodNodes(TreeNode* root) {
        int ans=0;
        helper(root,ans,root->val);
        return ans;
    }
};