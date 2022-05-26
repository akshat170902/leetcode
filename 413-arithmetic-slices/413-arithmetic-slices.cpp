class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans=0;
        
        vector<int>dp(nums.size(),0);
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]*2==nums[i-1]+nums[i+1]){
                dp[i]=dp[i-1]+1;
            }
            ans+=dp[i];
        }
        return ans;
    }
};