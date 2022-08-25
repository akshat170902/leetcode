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
    TreeNode* helper(vector<int>&i,vector<int>&p,int l,int h,int &idx){
        // cout<<l<<" "<<h<<endl;
        // cout<<idx<<endl;
        if(l<=h){
            int index=find(i.begin(),i.end(),p[idx])-i.begin();
            TreeNode*root=new TreeNode(p[idx]);
            idx--;
            root->right=helper(i,p,index+1,h,idx);
            root->left=helper(i,p,l,index-1,idx);
            return root;
        }
        return nullptr;
    }
    TreeNode* buildTree(vector<int>& i, vector<int>& p) {
        int in=p.size()-1;
        return helper(i,p,0,in,in);
    }
};