class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n=graph.size();
        vector<int>ans,indegree(n),vis(n);
        vector<vector<int>>g(n);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                g[graph[i][j]].push_back(i);
                indegree[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(!graph[i].size()){
                q.push(i);
            }
        }
        while(q.size()){
            int val=q.front();
            q.pop();
            for(auto&neig:g[val]){
                indegree[neig]--;
                if(!indegree[neig]){
                    q.push(neig);
                }
            }
            vis[val]++;
        }
        for(int i=0;i<n;i++){
            if(vis[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};