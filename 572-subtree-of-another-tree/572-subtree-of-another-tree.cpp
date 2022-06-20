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
    bool isEqual(TreeNode*&root,TreeNode*&sub){
        if(root==nullptr&&sub==nullptr)return true;
        if(root==nullptr||sub==nullptr)return false;
        if(root->val==sub->val){
            return isEqual(root->left,sub->left)&&isEqual(root->right,sub->right);
        }
        else{
            return false;
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr&&subRoot==nullptr)return true;
        if(root==nullptr||subRoot==nullptr)return false;
        bool flag=false;
        if(root->val==subRoot->val){
            flag= isEqual(root,subRoot);
        }
       
        
            return flag||isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
        
        
    }
};