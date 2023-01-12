class Solution {
public:
    vector<int> dfs(vector<vector<int>>&g,string &s,vector<int>&vis,int val,vector<int> &a){
        vector<int>temp(26);
        vis[val]=1;
        for(int neig:g[val]){
            if(!vis[neig]){
                vector<int> child= dfs(g,s,vis,neig,a);
                temp[s[neig]-'a']++;
                for(int i=0;i<26;i++){
                    temp[i]+=child[i];
                }
            }
        }
        a[val]+=temp[s[val]-'a']+1;
        return temp;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& e, string labels) {
        vector<vector<int>>g(n);
        for(int i=0;i<e.size();i++){
            g[e[i][0]].push_back(e[i][1]);
            g[e[i][1]].push_back(e[i][0]);
        }
        vector<int>vis(n),ans(n),temp(26);
        dfs(g,labels,vis,0,ans);
        return ans;
    }
};