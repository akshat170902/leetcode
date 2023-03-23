class Solution {
public:
    void dfs(int node,vector<vector<int>>&g,vector<int>&vis){
        vis[node]=0;
        for(auto&child:g[node]){
            if(vis[child]){
                dfs(child,g,vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& conn) {
        if(conn.size()<n-1){
            return -1;
        }
        vector<vector<int>>g(n);
        for(int i=0;i<conn.size();i++){
            g[conn[i][0]].push_back(conn[i][1]);
            g[conn[i][1]].push_back(conn[i][0]);
            
        }
        vector<int>vis(n,1);
        int connectedComponents=0;
        for(int i=0;i<n;i++){
            if(vis[i]){
                dfs(i,g,vis);
                connectedComponents++;
            }
        }
        return connectedComponents-1;
    }
};