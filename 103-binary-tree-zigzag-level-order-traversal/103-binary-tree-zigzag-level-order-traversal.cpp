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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==nullptr)return ans;
        stack<TreeNode*>p,q;
        bool flag=true;
        p.push(root);
        
        while(!p.empty()||!q.empty()){
            vector<int>v;
            if(flag){
                int n=p.size();
                for(int i=0;i<n;i++){
                    TreeNode*cur=p.top();
                    p.pop();
                    if(cur->left)q.push(cur->left);
                    if(cur->right)q.push(cur->right);
                    v.push_back(cur->val);
                    
                }
            }
            else{
                int n=q.size();
                for(int i=0;i<n;i++){
                    TreeNode*cur=q.top();
                    q.pop();
                    if(cur->right)p.push(cur->right);
                    if(cur->left)p.push(cur->left);
                    v.push_back(cur->val);
                   
                }
            }
             flag=!flag;
            ans.push_back(v);
        }
        return ans;
    }
};