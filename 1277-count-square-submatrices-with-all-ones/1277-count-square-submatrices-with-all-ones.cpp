class Solution {
public:
    int countSquares(vector<vector<int>>& m) {
        int sum=0;
        vector<vector<int>>dp(m.size()+1,vector<int>(m[0].size()+1,0));
        for(int i=1;i<=m.size();i++){
            for(int j=1;j<=m[0].size();j++){
                if(m[i-1][j-1]){
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+m[i-1][j-1];
                }
                sum+=dp[i][j];
            }
        }
        return sum;
    }
};