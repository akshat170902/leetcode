class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size()+2,0);
        for(int idx=cost.size()-1;idx>=0;idx--){
            dp[idx]=min(dp[idx+1],dp[idx+2])+cost[idx];
        }
        return min(dp[0],dp[1]);
    }
};