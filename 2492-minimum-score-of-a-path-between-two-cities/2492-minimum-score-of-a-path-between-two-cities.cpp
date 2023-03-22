class Solution {
public:
    void dfs(int node,vector<vector<pair<int,int>>>&graph,vector<int>&vis){
        vis[node]=0;
        for(auto&child:graph[node]){
            if(vis[child.first]){
                
                dfs(child.first,graph,vis);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
	
        vector<vector<pair<int,int>>>graph(n);
		//First we will create a graph with the given edges and weights
		//by making graph a vector of vector of pair
		
        for(auto&road:roads){
            
            graph[road[0]-1].push_back({road[1]-1,road[2]});
            graph[road[1]-1].push_back({road[0]-1,road[2]});
        }
		//for the dfs we require a visited array so we created a vis vector
        vector<int>vis(n,1);
		
        dfs(0,graph,vis);
        int res=1e9;
        for(int i=0;i<vis.size();i++){
            if(vis[i]){
                continue;
            }
            for(auto&child:graph[i]){
                res=min(res,child.second);
            }
        }
        return res;
    }
};