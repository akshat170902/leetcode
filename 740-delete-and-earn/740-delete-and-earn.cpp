class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
       sort(begin(nums),end(nums));
        vector<int>dp(n+1);
        for(int i=n-1;i>=0;i--){
           int nottake=dp[i+1];
            int a=nums[i];
            int idx=i;
            int sum=0;
            while(idx<n&&nums[idx]==a){
                idx++;
                sum+=a;
            }
            while(idx<n&&nums[idx]==a+1){
                idx++;
            }
            int take=sum+dp[idx];
            dp[i]=max(take,nottake);
        }
        return dp[0];
    }
};