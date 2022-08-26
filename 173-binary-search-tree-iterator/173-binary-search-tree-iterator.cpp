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
class BSTIterator {
    stack<TreeNode*>s;
    
public:
    BSTIterator(TreeNode* root) {
        TreeNode*cur=root;
        
        while(cur){
            s.push(cur);
            cur=cur->left;
        }
    }
    
    int next() {
        TreeNode*cur=s.top(),*ans=s.top();
        s.pop();
        if(cur->right){
            cur=cur->right;
            while(cur){
                s.push(cur);
                cur=cur->left;
            }
        }
        return ans->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */