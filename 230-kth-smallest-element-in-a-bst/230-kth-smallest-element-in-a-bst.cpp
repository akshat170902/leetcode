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
    // MOrisS TRaversaL
    int kthSmallest(TreeNode* root, int K){
        int val=0;
        TreeNode* cur=root;
        if(!root) return val;
        int c=0;
        while(cur){
           // cout<<cur->val;
        if(!cur->left){
            c++;
            if(c==K){
                val=cur->val;
            }
            cur=cur->right;
        }
        else{
            TreeNode* p=cur->left;
            while(p->right!=NULL&&p->right!=cur){
                p=p->right;                
            }
            if(!p->right){
                p->right=cur;
                cur=cur->left;
            }
            else{
                p->right=NULL;
                c++;
                if(c==K){
                    val=cur->val; 
                }                
                cur=cur->right;
            }
        }
      }
      return val;
    }
};