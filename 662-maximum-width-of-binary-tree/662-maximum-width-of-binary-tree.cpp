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
    int widthOfBinaryTree(TreeNode* root) {
        int ans=0;
        queue<pair<TreeNode*,long long >>q;
        if(root)
            q.push({root,0});
        while(!q.empty()){
            int n=q.size();
            int mini=q.front().second,rightVal=0,leftVal=0;
            for(int i=0;i<n;i++){
                auto p=q.front();
                // cout<<(p.second-mini)<<endl;
                
                q.pop();
                if(i==0){
                    leftVal=p.second;
                }
                if(i==n-1){
                    rightVal=p.second;
                }
                if(p.first->left){
                    q.push({p.first->left,(p.second-mini)*2+1});
                }
                if(p.first->right){
                    q.push({p.first->right,(p.second-mini)*2+2});
                }
            }
            // cout<<rightVal<<" "<<leftVal<<endl;
            ans=max(ans,rightVal-leftVal+1);
        }
        return ans;
    }
};