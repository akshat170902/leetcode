class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int p=1;
        int n=nums.size();
        vector<int>ans(n);
        for(int i=nums.size()-1;i>=0;i--){
            ans[i]=i==n-1?1:nums[i+1]*ans[i+1];
        }
        for(int i=0;i<n;i++){
            ans[i]=ans[i]*p;
            p=p*nums[i];
        }
        return ans;
    }
};