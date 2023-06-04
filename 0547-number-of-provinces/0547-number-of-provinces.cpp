class Solution {
public:
    void dfs(int node,vector<vector<int>>&g,vector<int>&vis){
        vis[node]=1;
        for(auto&child:g[node]){
            if(!vis[child]){
                dfs(child,g,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>g(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    g[i].push_back(j);
                }
            }
        }
        int Provinces=0;
        vector<int>vis(n);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                Provinces++;
                dfs(i,g,vis);
            }
        }
        return Provinces;
    }
};