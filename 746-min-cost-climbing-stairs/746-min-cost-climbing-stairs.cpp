class Solution {
public:
    int rec(int idx,vector<int>&cost,vector<int>&dp){
        if(idx>=cost.size())return 0;
        if(dp[idx]!=-1)return dp[idx];
        return dp[idx]= min(rec(idx+1,cost,dp),rec(idx+2,cost,dp))+cost[idx];
            
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size(),-1);
        return min(rec(1,cost,dp),rec(0,cost,dp));
    }
};