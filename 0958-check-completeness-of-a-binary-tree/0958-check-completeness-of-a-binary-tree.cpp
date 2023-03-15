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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        bool flag=true;
        while(q.size()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode*curRoot=q.front();
                q.pop();
                if(!flag){
                    if(curRoot->left||curRoot->right){
                        return false;
                    }
                }
                if(curRoot->left){
                    q.push(curRoot->left);
                    if(curRoot->right){
                        q.push(curRoot->right);
                    }
                    else{
                        flag=false;
                    }
                }
                else if(curRoot->right){
                    return false;
                }
                else{
                    flag=false;
                }
            }
            // cout<<n<<endl;
            if(q.size()&&((n&(n-1))!=0)){
                return false;
            }
        }
        return true;
    }   
};