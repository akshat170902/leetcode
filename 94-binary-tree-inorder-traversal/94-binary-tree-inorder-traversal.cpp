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
    TreeNode*RightFinder(TreeNode*cur,TreeNode*root){
        // TreeNode*cur=root;
        while(cur->right&&cur->right!=root){
            cur=cur->right;
        }
        return cur;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode*cur=root;
        vector<int>ans;
        while(cur){
            if(cur->left){
                TreeNode*rightMost=RightFinder(cur->left,cur);
                if(rightMost->right){
                    ans.push_back(cur->val);
                    rightMost->right=nullptr;
                    cur=cur->right;
                }
                else{
                    rightMost->right=cur;
                    cur=cur->left;
                }
            }
            else{
                ans.push_back(cur->val);
                cur=cur->right;
            }
        }
        return ans;
    }
};