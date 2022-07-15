class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),0);
        for(int idx=nums.size()-2;idx>=0;idx--){
            int ans=1e9;
            for(int i=1;i<=nums[idx]&&i+idx<nums.size();i++){
                ans=min(ans,dp[idx+i]+1);
            }
        dp[idx]=ans;
        }
        return dp[0];
    }
};