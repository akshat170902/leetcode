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
    void inorderTraversal(TreeNode*&root,vector<TreeNode*>&inorder){
        if(!root)return ;
        inorderTraversal(root->left,inorder);
        inorder.push_back(root);
        inorderTraversal(root->right,inorder);
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*>inorder;
        inorderTraversal(root,inorder);
        bool flag=true;
        int first=-1,second=-1,third=-1;
        for(int i=0;i<inorder.size()-1;i++){
            if(inorder[i]->val>inorder[i+1]->val){
                if(flag){
                first=i;
                second=i+1;
                flag=false;
                }
                else{
                    third=i+1;
                    break;
                }
            }
        }
        if(third!=-1){
            int temp=inorder[first]->val;
            inorder[first]->val=inorder[third]->val;
            inorder[third]->val=temp;
        }
        else{
            int temp=inorder[first]->val;
            inorder[first]->val=inorder[second]->val;
            inorder[second]->val=temp;
        }
    }
};