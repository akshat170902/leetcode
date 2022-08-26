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
    bool findTarget(TreeNode* root, int k) {
        vector<int>ans;
        TreeNode*cur=root;
        while(cur){
            TreeNode*leftNode=cur->left;
            if(leftNode){
                while(leftNode->right&&leftNode->right!=cur){
                    leftNode=leftNode->right;
                }
                if(leftNode->right){
                    leftNode->right=nullptr;
                    ans.push_back(cur->val);
                    cur=cur->right;
                }
                else{
                    leftNode->right=cur;
                    cur=cur->left;
                }
            }
            else{
                ans.push_back(cur->val);
                cur=cur->right;
            }
        }
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<endl;
        }
        int l=0,r=ans.size()-1;
        while(l<r){
            if(ans[l]+ans[r]==k){
                return true;
            }
            else if(ans[l]+ans[r]<k){
                l++;
            }
            else{
                r--;
            }
        }
        return false;
    }
};