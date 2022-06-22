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
    stack<int>s;
public:
    BSTIterator(TreeNode* root) {
        Inorder(root,s);
        
    }
    void Inorder(TreeNode*root,stack<int>&s){
        if(root==nullptr)return;
        Inorder(root->right,s);
        s.push(root->val);
        Inorder(root->left,s);
    }
    int next() {
   
            int j=s.top();
            s.pop();
            return j;
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