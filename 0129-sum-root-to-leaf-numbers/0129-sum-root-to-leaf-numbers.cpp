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
    void helper(TreeNode*&root,string s,vector<string>&v){
        if(root==nullptr)return;
        if(root->left==nullptr&&root->right==nullptr){
            s+=to_string(root->val);
            v.push_back(s);
            return;
        }
        s+=to_string(root->val);
        helper(root->left,s,v);
        helper(root->right,s,v);
    }
    int sumNumbers(TreeNode* root) {
        vector<string>v;
        string s="";
        helper(root,s,v);
        int sum=0;
        for(int i=0;i<v.size();i++){
            sum+=stoi(v[i]);
        }
        return sum;
    }
};