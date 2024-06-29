class Solution {
public:
    void dfs(int node,int par,vector<vector<int>>&g,vector<vector<int>>&r,vector<int>&v){
        v[node]=1;
        if(node!=par)
            r[node].push_back(par);
        for(auto&e:g[node]){
            if(v[e]==0){
                dfs(e,par,g,r,v);
            }
        }
        
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n),result(n);
        for(auto&edge:edges){
            graph[edge[0]].push_back(edge[1]);
        }
        for(int i=0;i<n;i++){
            vector<int>vis(n);
            dfs(i,i,graph,result,vis);
        }
        
        return result;
    }
};