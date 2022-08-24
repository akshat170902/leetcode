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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        queue<pair<TreeNode*,pair<int,int>>>q;
        unordered_map<int,unordered_map<int,vector<int>>>m;
        
        if(root){
            q.push({root,{0,0}});
            m[0][0].push_back(root->val);
        }
        int mini=0,maxi=0,height=0;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* p=q.front().first;
                int x=q.front().second.second;
                int y=q.front().second.first;
                q.pop();
                
                if(p->left){
                    // cout<<p->left->val<<endl;
                    // cout<<x<<" "<<y<<endl;
                    m[y+1][x-1].push_back(p->left->val);
                    // cout<<m[y+1][x-1][0];
                    // if(m[y+1][x-1].size()>1&&m[y+1][x-1][0]>p->left->val){
                    //     swap(m[y+1][x-1][0],m[y+1][x-1][1]);
                    // }
                    q.push({p->left,{y+1,x-1}});
                    mini=min(mini,x-1);
                    height=max(y+1,height);
                }
                if(p->right){
                    m[y+1][x+1].push_back(p->right->val);
                    // if(m[y+1][x+1].size()>1&&m[y+1][x+1][0]>p->right->val){
                    //     swap(m[y+1][x+1][0],m[y+1][x+1][1]);
                    // }
                    q.push({p->right,{y+1,x+1}});
                    maxi=max(maxi,x+1);
                    height=max(y+1,height);
                }
            }
        }
        
        for(int i=mini;i<=maxi;i++){
            vector<int>v;
            for(int j=0;j<=height;j++){
                
                if(m[j].count(i)){
                    sort(m[j][i].begin(),m[j][i].end());
                    for(int k=0;k<m[j][i].size();k++){
                        v.push_back(m[j][i][k]);
                    }
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};