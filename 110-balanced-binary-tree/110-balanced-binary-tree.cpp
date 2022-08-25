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
    bool Balanced(TreeNode*root,int& h){
        if(!root)
            return true;
        int l=0,r=0;
        bool leftB=Balanced(root->left,l);
        bool rightB=Balanced(root->right,r);
        h=max(l,r)+1;
        return abs(l-r)<=1?leftB&&rightB:false;
    }
    bool isBalanced(TreeNode* root) {
        int h=0;
        return Balanced(root,h);
    }
};