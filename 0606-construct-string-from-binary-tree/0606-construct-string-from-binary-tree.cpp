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
    string tree2str(TreeNode* root) {
        string s="";
        if(root==nullptr){
            return s;
            
        }
        string sl=tree2str(root->left);
        string sr=tree2str(root->right);
        s+=to_string(root->val);
        if(sl!=""){
            s=s+'('+sl+')';
        }
        if(sr!=""){
            if(sl==""){
                s=s+"()";
            }
            s=s+'('+sr+')';
        }
        return s;
    }
};