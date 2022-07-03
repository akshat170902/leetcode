class Solution {
public:
    int rec(int idx,vector<int>&prices,int buy,vector<vector<int>>&dp){
        if(idx==prices.size()){
            return 0;
        }
        if(dp[idx][buy]!=-1)return dp[idx][buy];
        int take=0,notTake=0;
        if(buy){
            take=rec(idx+1,prices,0,dp)-prices[idx];
            notTake=rec(idx+1,prices,1,dp);
        }
        else{
            take=prices[idx];
            notTake=rec(idx+1,prices,0,dp);
        }
        return dp[idx][buy]= max(take,notTake);
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return rec(0,prices,1,dp);
    }
};