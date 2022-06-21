/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int searchnode(TreeNode*root,TreeNode*target){
        if(root==nullptr)return -1;
        if(root==target)return 0;
       int l= searchnode(root->left,target);
       int r= searchnode(root->right,target);
        if(l!=-1)return l+1;
        if(r!=-1)return r+1;
        return -1;
    }
    void subtree(TreeNode*root,int k,vector<int>&v){
        if(root==nullptr)return;
        if(k==0)v.push_back(root->val);
        subtree(root->left,k-1,v);
        subtree(root->right,k-1,v);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>v;
        if(root==target){
            subtree(root,k,v);
            
        }
       int l= searchnode(root->left,target);
        int r=searchnode(root->right,target);
        if(l!=-1){
           v= distanceK(root->left,target,k);
            if(l+1==k)v.push_back(root->val);
            else
            subtree(root->right,k-l-2,v);
            
        }
        if(r!=-1){
            v=distanceK(root->right,target,k);
            if(r+1==k)v.push_back(root->val);
            else
            subtree(root->left,k-r-2,v);
        }
        return v;
    }
};