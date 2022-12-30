class Solution {
public:
    void dfs(int tar,vector<vector<int>>&graph,vector<vector<int>>&ans,vector<int>&temp,vector<int>&vis){
        if(tar==graph.size()-1){
            temp.push_back(tar);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        vis[tar]=1;
        temp.push_back(tar);
        for(auto&it:graph[tar]){
            if(!vis[it])
                dfs(it,graph,ans,temp,vis);
        }
        temp.pop_back();
        vis[tar]=0;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>temp,vis(graph.size(),0);
        dfs(0,graph,ans,temp,vis);
        return ans;
    }
};