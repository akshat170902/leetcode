class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
       
    vector<vector<int>>dp(prices.size()+2,vector<int>(2));
    for(int i=prices.size()-1;i>=0;i--){
        for(int j=0;j<=1;j++){
            if(j){
                dp[i][j]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
            }
            else{
                dp[i][j]=max(prices[i]+dp[i+1][1]-fee,dp[i+1][0]);
            }
        }
    }
    return dp[0][1];
}
    
};