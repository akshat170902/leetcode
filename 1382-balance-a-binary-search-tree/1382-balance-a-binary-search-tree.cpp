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
    void inorder(TreeNode*root,vector<int>&v){
        if(root){
            inorder(root->left,v);
            v.push_back(root->val);
            inorder(root->right,v);
        }
    }
    TreeNode*rec(TreeNode*root,vector<int>&v,int l,int h){
        if(l>h){
            return NULL;
        }
        int mid=(l+h)/2;
        TreeNode*leftNode=rec(root,v,l,mid-1);
        TreeNode*rightNode=rec(root,v,mid+1,h);
        return new TreeNode(v[mid],leftNode,rightNode);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>v;
        inorder(root,v);
        return rec(root,v,0,v.size()-1);
    }
};