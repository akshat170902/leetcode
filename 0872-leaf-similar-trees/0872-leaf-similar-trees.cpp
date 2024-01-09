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
    void helper(TreeNode*root,vector<int>&v){
        if(root==nullptr)return;
        if(root->left==nullptr&&root->right==nullptr){
            v.push_back(root->val);
            return;
        }
        helper(root->left,v);
        helper(root->right,v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>v,c;
        helper(root1,v);
        helper(root2,c);
        bool b=true;
        if(v.size()!=c.size())
            b=false;
        for(int i=0;i<v.size();i++){
            if(v[i]!=c[i]){
                b=false;
                break;
            }
        }
        return b;
    }
};