class Solution {
public:
    int dfs(int node,vector<int>&g,vector<int>&vis,vector<int>&dp){
        int child=g[node];
        vis[node]=0;
        if(child==-1){
            return -1;
        }
        
        int ans=-1;
        if(vis[child]){
            int val=dfs(child,g,vis,dp);
            if(val!=-1){
                ans=val+1;
            }
        }
        
        else{
            if(dp[child]==-1){
                ans=1;
                vis[child]=1;
            }
            
        }
        
        if(vis[node]){
            dp[node]=max(dp[node],ans);
            return -1;
        }
        
        return ans;
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int>vis(n,1),dp(n,-1);
        int ans=-1;
        for(int i=0;i<n;i++){
            if(vis[i]){
                dfs(i,edges,vis,dp);
            }
            
        }
        for(int i=0;i<n;i++){
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};