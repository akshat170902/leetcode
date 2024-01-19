class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX;
        int n=matrix.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(j==n){
                    dp[i][j]=min(dp[i-1][j-1],dp[i-1][j])+matrix[i-1][j-1];
                 
                }
               else if(j==1){
                    dp[i][j]=min(dp[i-1][j],dp[i-1][j+1])+matrix[i-1][j-1];
                } 
                else{
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i-1][j+1]))+matrix[i-1][j-1];
                }
                if(i==n){
                    ans=min(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }
};