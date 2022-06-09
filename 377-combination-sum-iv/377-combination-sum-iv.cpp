class Solution {
public:
    int helper(int tar,vector<int>&nums,vector<int>&dp){
        if(tar==0)return 1;
        if(tar<0)return 0;
        if(dp[tar]!=-1)return dp[tar];
        int sum=0;
        
        for(int i=0;i<nums.size()&&tar>=nums[i];i++){
           sum+= helper(tar-nums[i],nums,dp);
        }
        return dp[tar]= sum;
    }
    int combinationSum4(vector<int>& nums, int target) {
        sort(begin(nums),end(nums));
        vector<int>dp(target+1,-1);
       return helper(target,nums,dp);
    }
};