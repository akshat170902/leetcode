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
    int isPalindrome(vector<int>&arr){
        int n=arr.size();
        int sum=0;
        int one=0,zero=0;
        for(int i=0;i<n;i++){
            if(arr[i]%2){
                one++;
            }
            else{
                zero++;
            }
            sum+=arr[i];
        }
        if(sum%2==0){
            return one==0;
        }
        return one==1;
    }
    int rec(TreeNode*root,vector<int>arr){
        // cout<<root->val<<endl;
        if(!root->left&&!root->right){
            arr[root->val]++;
            
            int ans=isPalindrome(arr);
            // cout<<ans<<endl;
            return ans;
        }
        int val=0;
        arr[root->val]++;
        if(root->left){
            val+=rec(root->left,arr);
        }
        if(root->right){
            val+=rec(root->right,arr);
        }
        return val;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        if(!root->left&&!root->right)
            return 1;
        
        vector<int>arr(10,0);
        
        int ans=rec(root,arr);
        return ans;
    }
};