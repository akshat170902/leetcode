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
    bool isEqual(TreeNode*r,TreeNode*s){
        if(r==nullptr&&s==nullptr)return true;
        if(r==nullptr||s==nullptr)return false;
        if(r->val==s->val){
            return isEqual(r->left,s->right)&&isEqual(r->right,s->left);
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
       return isEqual(root->left,root->right);
    }
};