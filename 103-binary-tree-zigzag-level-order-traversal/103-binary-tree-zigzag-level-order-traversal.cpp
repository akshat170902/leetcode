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
        stack<TreeNode*>s1,s2;
        vector<vector<int>>ans;
        bool flag=true;
        if(root){
            s1.push(root);
        }
        while(!s1.empty()||!s2.empty()){
            vector<int>temp;
            if(flag){
                int n=s1.size();
                for(int i=0;i<n;i++){
                    TreeNode*p=s1.top();
                    s1.pop();
                    temp.push_back(p->val);
                    if(p->left)
                        s2.push(p->left);
                    if(p->right)
                        s2.push(p->right);
                    
                }
                flag=false;
            }
            else{
                int n=s2.size();
                for(int i=0;i<n;i++){
                    TreeNode*p=s2.top();
                    s2.pop();
                    temp.push_back(p->val);
                    if(p->right)
                        s1.push(p->right);
                    if(p->left)
                        s1.push(p->left);
                    
                }
                flag=true;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};