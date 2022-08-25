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
    int findIdx(int val,vector<int>&arr,int l,int r){
        for(int i=l;i<=r;i++){
            if(arr[i]==val){
                return i;
            }
        }
        return -1;
    }
    TreeNode*helper(vector<int>&p,vector<int>&i,int a,int b,int c,int d){
        // cout<<a<<" "<<b<<"  "<<c<<" "<<d<<endl;
        if(a<=b&&c<=d){
            int in=findIdx(i[a],p,c,d);
            if(in==-1)
                return nullptr;
            TreeNode*root=new TreeNode(i[a]);
            TreeNode*l=helper(p,i,a+1,a+in-c,c,in-1);
            TreeNode*r=helper(p,i,a+in+1-c,b,in+1,d);
            root->left=l;
            root->right=r;
            return root;
        }
        return nullptr;
    }
    TreeNode* buildTree(vector<int>& p, vector<int>& i) {
        return helper(i,p,0,p.size()-1,0,i.size()-1);
        
    }
};