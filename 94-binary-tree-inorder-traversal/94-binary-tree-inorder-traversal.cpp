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
    vector<int> inorderTraversal(TreeNode* root) {
        
            
        stack<pair<TreeNode*,int>>s;
        vector<int>inorder,preorder,postorder;
        if(root)
            s.push({root,1});
        while(!s.empty()){
            int val=s.top().second;
            TreeNode*cur=s.top().first;
            s.pop();
            if(val==1){
                preorder.push_back(cur->val);
                val++;
                s.push({cur,val});
                if(cur->left)
                    s.push({cur->left,1});
            }
            else if(val==2){
                inorder.push_back(cur->val);
                val++;
                s.push({cur,val});
                if(cur->right)
                    s.push({cur->right,1});
            }
            else{
                postorder.push_back(cur->val);
                
            }
        }
        return inorder;
    }
};