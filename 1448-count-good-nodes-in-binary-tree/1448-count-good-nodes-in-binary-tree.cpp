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
    int good(TreeNode*&root,int maxAbove){
        if(!root){
            return 0;
        }
        int ans=0;
        if(maxAbove<=root->val){
            maxAbove=root->val;
            ans++;
        }
        return ans+good(root->left,maxAbove)+good(root->right,maxAbove);
    }
    int goodNodes(TreeNode* root) {
        return good(root,-1e5);
    }
};