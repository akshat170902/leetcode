class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int>dp(m+1,1e9),forw(m+1,1e9);
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1&&j==m-1){
                    dp[j]=grid[i][j];
                    continue;
                }
                dp[j]=min(forw[j],dp[j+1])+grid[i][j];
            }
            forw=dp;
        }
        return dp[0];
    }
};