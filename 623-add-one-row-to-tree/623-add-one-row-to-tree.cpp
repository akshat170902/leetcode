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
    void height(TreeNode*&root,int depth,int &val){
        if(depth==1){
            TreeNode*p=new TreeNode(val);
            p->left=root;
            p->right=nullptr;
            root=p;
        }
        if(depth-1==1){
          TreeNode*l=root->left;
            TreeNode*r=root->right;
            root->left=new TreeNode(val);
            root->right=new TreeNode(val);
            root->left->left=l;
            root->right->right=r;
            return;
        }
        if(root->left)
            height(root->left,depth-1,val);
        if(root->right)
        height(root->right,depth-1,val);
        }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        height(root,depth,val);
        return root;
    }
};