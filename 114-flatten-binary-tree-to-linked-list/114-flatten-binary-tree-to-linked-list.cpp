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
    TreeNode* flatten(TreeNode* root) {
        if(root==nullptr)
            return nullptr;
        if(root->left==nullptr&&root->right==nullptr)
            return root;
        TreeNode*l=root->left;
        TreeNode*r=root->right;
        
        TreeNode*lTail=flatten(root->left);
        TreeNode*rTail=flatten(root->right);
        
        if(lTail){
            
            root->left=nullptr;
            root->right=l;
            lTail->right=r;
            if(rTail)
                return rTail;
            return lTail;
        }
        return rTail;
    }
};