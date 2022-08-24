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
    vector<int> postorderTraversal(TreeNode* root) {
    
        stack<TreeNode*>s;
        vector<int>ans;
        
        TreeNode*cur=root;
        
        while(!s.empty()||cur){
            if(cur){
                s.push(cur);
                cur=cur->left;
            }
            else{
                TreeNode*temp=s.top()->right;
                if(temp){
                    cur=temp;
                }
                else{
                    temp=s.top();
                    s.pop();
                    ans.push_back(temp->val);
                    while(!s.empty()&&temp==s.top()->right){
                        temp=s.top();
                        s.pop();
                        ans.push_back(temp->val);
                        
                    }
                    
                }
            }
        }
        return ans;
    }
};