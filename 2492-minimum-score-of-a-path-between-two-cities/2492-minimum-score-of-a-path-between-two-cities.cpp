class Solution {
public:
    void dfs(int node,vector<vector<pair<int,int>>>&graph,vector<int>&vis,vector<int>&ans){
        vis[node]=0;
        for(auto&child:graph[node]){
            if(vis[child.first]){
                ans.push_back(child.first);
                dfs(child.first,graph,vis,ans);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int>vis(n,1);
        vector<vector<pair<int,int>>>graph(n);
        for(auto&road:roads){
            
            graph[road[0]-1].push_back({road[1]-1,road[2]});
            graph[road[1]-1].push_back({road[0]-1,road[2]});
        }
        
        vector<int>ans;
        dfs(0,graph,vis,ans);
        int res=1e9;
        for(int i=0;i<ans.size();i++){
            for(auto&child:graph[ans[i]]){
                res=min(res,child.second);
            }
        }
        return res;
    }
};