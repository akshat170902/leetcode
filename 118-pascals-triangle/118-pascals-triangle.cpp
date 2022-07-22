class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>dp(numRows);
        for(int i=0;i<numRows;i++){
            for(int j=0;j<i+1;j++){
                if(j==0||j==i){
                    dp[i].push_back(1);
                }
                else {
                    dp[i].push_back(dp[i-1][j-1]+dp[i-1][j]);
                }
            }
        }
        return dp;
    }
};