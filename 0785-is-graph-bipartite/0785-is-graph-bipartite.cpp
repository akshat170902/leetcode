class Solution {
public:
    bool isBipartite_dfs(vector<vector<int>>&graph,int node,int col,vector<pair<bool,int>>&vis){
        vis[node].first=true;
        vis[node].second=col;
        for(int i=0;i<graph[node].size();i++){
            if(vis[graph[node][i]].first==false){
               if(! isBipartite_dfs(graph,graph[node][i],1-col,vis)){
                   return false;
               }
            }
            else{
                if(vis[graph[node][i]].second==col){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<pair<bool,int>>vis(n,{false,-1});
        for(int i=0;i<n;i++){
            if(vis[i].first==false){
            if(isBipartite_dfs(graph,i,0,vis)==false){
                return false;
            }
        }
    }
        return true;
    }
};