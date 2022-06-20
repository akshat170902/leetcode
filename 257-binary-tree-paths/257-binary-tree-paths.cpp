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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>v;
        if(root==nullptr){
            return v;
        }
        if(!root->left&&!root->right){
            v.push_back(to_string(root->val));
            return v;
        }
        
        vector<string>l=binaryTreePaths(root->left);
        vector<string>r=binaryTreePaths(root->right);
        for(int i=0;i<l.size();i++){
            string s=to_string(root->val)+"->"+l[i];
            
            v.push_back(s);
        }
        for(int i=0;i<r.size();i++){
            string s=to_string(root->val)+"->"+r[i];
            
            v.push_back(s);
        }
        return v;
    }
};