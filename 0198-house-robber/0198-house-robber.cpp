class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(2));
        for(int i=1;i<=n;i++){
            dp[i][0]=dp[i-1][1]+nums[i-1];
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]);
        }
        return max(dp[n][0],dp[n][1]);
    }
};