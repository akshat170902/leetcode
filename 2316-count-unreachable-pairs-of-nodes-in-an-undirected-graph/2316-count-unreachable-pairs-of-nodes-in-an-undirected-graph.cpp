class Solution {
public:
    long long dfs(int node,vector<vector<long long>>&g,vector<long long>&vis){
        vis[node]=0;
        int nodeVis=0;
        for(auto&child:g[node]){
            if(vis[child]){
                nodeVis+=dfs(child,g,vis);
            }
        }
        return nodeVis+1;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<long long>>g(n);
        for(auto&edge:edges){
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        vector<long long>vis(n,1),a;
        for(int i=0;i<n;i++){
            if(vis[i]){
                a.push_back(dfs(i,g,vis));
            }
        }
        int m=a.size();
        vector<long long>sum=a;
        
        for(int i=m-2;i>=0;i--){
            sum[i]+=sum[i+1];
        }
        long long ans=0;
        for(int i=0;i<m-1;i++){
            ans+=a[i]*sum[i+1];
        }
        return ans;
    }
};