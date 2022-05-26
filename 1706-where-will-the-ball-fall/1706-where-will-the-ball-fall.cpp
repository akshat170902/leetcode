class Solution {
public:
    vector<int> findBall(vector<vector<int>>& g) {
          vector<vector<int>>dp(g.size()+1,vector<int>(g[0].size()+1));
        for(int i=0;i<g[0].size();i++){
            dp[0][i]=i+1;
        }
        for(int i=1;i<=g.size();i++){
            for(int j=0;j<g[i-1].size()-1;j++){
                 if(g[i-1][j]==g[i-1][j+1]){
                     if(g[i-1][j]==1)
                     dp[i][j+g[i-1][j]]=dp[i-1][j];
                     if(g[i-1][j]==-1)
                     dp[i][j]=dp[i-1][j-g[i-1][j]];
                 }
            }
        }
        vector<int>v(g[0].size(),-1);
        for(int i=0;i<dp[g.size()].size();i++){
            if(dp[g.size()][i]>0){
                v[dp[g.size()][i]-1]=i;
            }
        }
        return v;
        
    }
};