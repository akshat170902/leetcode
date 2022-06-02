class Solution {
public:
     
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int>dp(amount+1,1e9),prev(amount+1,1e9);
        for(int i=n-1;i>=0;i--){
            dp[0]=0;
            for(int j=1;j<=amount;j++){
                int nottake=prev[j];
                int take=j>=coins[i]?dp[j-coins[i]]+1:1e9;
                dp[j]=min(take,nottake);
            }
            prev=dp;
        }
        return dp[amount]>=1e9?-1:dp[amount];
    }
};