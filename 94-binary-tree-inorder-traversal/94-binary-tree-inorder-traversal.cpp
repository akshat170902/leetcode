
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>s;
        TreeNode*cur=root;
        vector<int>ans;
        while(1){
            if(cur){
                s.push(cur);
                cur=cur->left;
            }
            else{
                if(s.empty())
                    break;
                cur=s.top();
                s.pop();
                ans.push_back(cur->val);
                cur=cur->right;
            }
        }
        return ans;
    }
};