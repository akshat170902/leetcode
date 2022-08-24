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
        stack<TreeNode*>s1,s2;
        if(root)
        s1.push(root);
        while(s1.size()){
            TreeNode*p=s1.top();
            s1.pop();
            s2.push(p);
            if(p->left){
                s1.push(p->left);
            }
            if(p->right){
                s1.push(p->right);
            }
        }
        vector<int>ans;
        while(s2.empty()==false){
            ans.push_back(s2.top()->val);
            s2.pop();
            
        }
        return ans;
    }
};