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
    int subtree(TreeNode*root,long long int tar){
        
        if(root==nullptr)return 0;
        long long int ans=0;
        if(tar-root->val==0)ans=1;
        return ans+subtree(root->left,tar-root->val)+subtree(root->right,tar-root->val);
    }
    int pathSum(TreeNode* root, int targetSum) {
        
        if(root==nullptr)return 0;
       int l= subtree(root,targetSum);
       
        return l+ pathSum(root->left,targetSum)+pathSum(root->right,targetSum);
        // return 0;
    }
};