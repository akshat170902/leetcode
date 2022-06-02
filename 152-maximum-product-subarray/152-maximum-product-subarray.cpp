class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0],least=nums[0],most=nums[0];
        for(int i=1;i<nums.size();i++){
            int temp=max(max(most*nums[i],least*nums[i]),nums[i]);
            least=min(nums[i],min(most*nums[i],least*nums[i]));
            most=temp;
            ans=max(ans,most);
        }
        return ans;
    }
};