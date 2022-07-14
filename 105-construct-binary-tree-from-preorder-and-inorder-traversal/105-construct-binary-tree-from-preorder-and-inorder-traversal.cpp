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
    int findidc(vector<int>ino,int l,int r,int m){
        int idx=-1;
        for(int i=l;i<r+1;i++){
            if(ino[i]==m)
                idx=i;
            
        }
        return idx;
    }
    TreeNode *helper(vector<int>pre,vector<int>ino,int l,int r,int &i){
        if(l>r){
            return nullptr;
        }
        TreeNode*p=new TreeNode(pre[i]);
        int m=pre[i];
        int j=findidc(ino,l,r,m);
        i++;
        p->left=helper(pre,ino,l,j-1,i);
        p->right=helper(pre,ino,j+1,r,i);
        return p;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i=0;
        return helper(preorder,inorder,0,inorder.size()-1,i);
    }
};