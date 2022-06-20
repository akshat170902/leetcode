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
    bool helper(TreeNode*root,int &l){
        if(root==nullptr)return true;
        int lh=0,rh=0;
       bool left= helper(root->left,lh);
        bool right=helper(root->right,rh);
        l=max(lh,rh)+1;
        if(abs(lh-rh)>1){
            return false;
        }
        return left&&right;
        
    }
    bool isBalanced(TreeNode* root) {
        int l=0;
       return helper(root,l);
    }
};