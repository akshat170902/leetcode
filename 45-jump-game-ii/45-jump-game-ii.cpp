class Solution {
public:
    int rec(vector<int>&nums,int idx,vector<int>&dp){
        if(idx>=nums.size()){
            return 1e9;
        }
        if(idx==nums.size()-1){
            return 0;
        }
        if(dp[idx]!=-1)return dp[idx];
        int ans=1e9;
        for(int i=1;i<=nums[idx];i++){
            ans=min(ans,rec(nums,idx+i,dp)+1);
        }
        return dp[idx]=ans;
    }
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return rec(nums,0,dp);
    }
};