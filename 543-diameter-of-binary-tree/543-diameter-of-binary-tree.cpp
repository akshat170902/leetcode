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
    int diameter(TreeNode*root,int &H){
        if(root==nullptr)
            return 0;
        int l=0,r=0;
        int d1=diameter(root->left,l);
        int d2=diameter(root->right,r);
        H=max(l,r)+1;
        return max(l+r+1,max(d1,d2));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int leftH=0,rightH=0;
       
        int ans= diameter(root,leftH);
        // cout<<leftH<<endl;
        return ans-1;
    }
};